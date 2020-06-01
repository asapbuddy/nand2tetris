#include <bitset>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "../AssemblerLib/Core/DefaultModuleFabric.h"
#include "../AssemblerLib/Core/Helper.h"
#include "../core/Parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    const uint8_t bitness = 16;
    DefaultModuleFabric<bitness> fabric;

    auto parser = fabric.get_parser_module();

    auto sym_table = fabric.get_symbol_table();
    auto* path = "..\\AssemblerTests\\Tests\\PongL.asm";
    try
    {
        const auto init_result = parser->init(path);
        if(init_result)
        {
            //TODO print error
        }
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }

    std::vector<std::string> result;
    int lines_counter = 0;

    while(parser->has_more_commands())
    {
        parser->advance();
        const auto command_type = parser->command_type();
        switch(command_type)
        {
        case CommandType::a_command:
            lines_counter++;
            break;
        case CommandType::l_command:
            sym_table->add_entry(parser->symbol(), lines_counter);
            break;
        case CommandType::c_command:
            lines_counter++;
            break;
        default:
            break;
        }
    }

    parser->reset();
    parser->init(path);

    int a_counter = 16;
    while(parser->has_more_commands())
    {
        parser->advance();
        const auto command_type = parser->command_type();

        switch(command_type)
        {
        case CommandType::a_command:
        {
            auto symbol = parser->symbol();

            if(Helper::is_digit(symbol))
                result.emplace_back(bitset<bitness>(stoi(symbol)).to_string());
            else
            {
                if(!sym_table->contains(symbol))
                    sym_table->add_entry(symbol, a_counter++);

                result.emplace_back(bitset<bitness>(sym_table->address(symbol)).to_string());
            }

            break;
        }
        case CommandType::c_command:
        {
            std::bitset<16> mask(0);
            mask |= 0b111 << 13;
            mask |= std::bitset<16>(parser->comp());
            mask |= std::bitset<16>(parser->dest());
            mask |= std::bitset<16>(parser->jump());

            result.push_back(mask.to_string());
            break;
        }
        default:
            break;
        }
    }
    std::ofstream output_file("..\\AssemblerTests\\Tests\\PongL.hack");
    ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(result.begin(), result.end(), output_iterator);
    return 0;
}
