#include "Assembler.h"

void Assembler::init() const
{
    parser_->init(file_path_);
}

void Assembler::process_labels() const
{
    parser_->reset();

    auto& fabric = FabricModule::get_instance();
    auto symbol_table_ = fabric.get_symbol_table();

    unsigned lines_counter = 0;
    while(parser_->advance())
    {
        if(parser_->command_type() == CommandType::l_command)
        {
            const auto mnemonic_ = Helper::Process(parser_->get_command());
            symbol_table_->add_entry(mnemonic_, lines_counter);
        }
        else
            lines_counter++;
    }
}

void Assembler::compile()
{
    parser_->reset();
    while(parser_->advance())
    {
        const auto command_type = parser_->command_type();
        if(command_type != CommandType::l_command)
            result_.emplace_back(Helper::Process(parser_->get_command()));

        /*
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
        }*/
    }
}

void Assembler::save(const char* ext)
{
    const std::string fn(file_path_);
    auto dot = fn.rfind('.', fn.length());

    const auto output_fn = dot == std::string::npos ? fn + ext : fn.substr(0, dot + 1) + ext;
    std::ofstream output_file(output_fn);
    const std::ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(result_.begin(), result_.end(), output_iterator);
    output_file.close();
}
