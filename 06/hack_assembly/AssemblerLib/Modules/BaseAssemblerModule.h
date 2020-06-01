#pragma once
#include <bitset>
#include <fstream>
#include <iterator>
#include <vector>

#include "../API/IParserModule.h"
#include "../API/ISymbolTable.h"
#include "../Core/DefaultModuleFabric.h"
#include "../Core/Helper.h"

template <uint8_t bitness>
class BaseAssemblerModule
{
    const char* file_path_;
    IParserModule* parser_ = nullptr;
    ISymbolTable* symbol_table_ = nullptr;
    std::vector<std::string> result_;
public:
    BaseAssemblerModule(const char* path, IModuleFabric* fabric)
        : file_path_(path)
    {
        if(fabric != nullptr)
        {
            parser_ = fabric->get_parser_module();
            symbol_table_ = fabric->get_symbol_table();
        }
    }

    ~BaseAssemblerModule()
    {
        delete symbol_table_;
        delete parser_;
    }

    bool init() const
    {
        return parser_->init(file_path_);
    }

    void process_labels() const
    {
        auto lines_counter = 0;

        while(parser_->has_more_commands())
        {
            parser_->advance();
            const auto command_type = parser_->command_type();
            switch(command_type)
            {
            case CommandType::a_command:
                lines_counter++;
                break;
            case CommandType::l_command:
                symbol_table_->add_entry(parser_->symbol(), lines_counter);
                break;
            case CommandType::c_command:
                lines_counter++;
                break;
            default:
                break;
            }
        }
    }

    void compile()
    {
        parser_->reset();
        parser_->init(file_path_);

        auto a_counter = 16;
        while(parser_->has_more_commands())
        {
            parser_->advance();
            const auto command_type = parser_->command_type();

            switch(command_type)
            {
            case CommandType::a_command:
            {
                auto symbol = parser_->symbol();

                if(Helper::is_digit(symbol))
                    result_.emplace_back(std::bitset<bitness>(stoi(symbol)).to_string());
                else
                {
                    if(!symbol_table_->contains(symbol))
                        symbol_table_->add_entry(symbol, a_counter++);

                    result_.emplace_back(std::bitset<bitness>(symbol_table_->address(symbol)).to_string());
                }

                break;
            }
            case CommandType::c_command:
            {
                std::bitset<16> mask(0);
                mask |= 0b111 << 13;
                mask |= std::bitset<16>(parser_->comp());
                mask |= std::bitset<16>(parser_->dest());
                mask |= std::bitset<16>(parser_->jump());

                result_.push_back(mask.to_string());
                break;
            }
            default:
                break;
            }
        }
    }

    void save(const char* ext)
    {
        const std::string fn(file_path_);
        auto dot = fn.rfind('.', fn.length());

        const auto output_fn = dot == std::string::npos ? fn + ext : fn.substr(0, dot + 1) + ext;
        std::ofstream output_file(output_fn);
        const std::ostream_iterator<std::string> output_iterator(output_file, "\n");
        std::copy(result_.begin(), result_.end(), output_iterator);
        output_file.close();
    }
};
