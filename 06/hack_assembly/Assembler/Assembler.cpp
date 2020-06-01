#include <bitset>
#include <iostream>
#include <string>
#include <vector>

#include "../AssemblerLib/Core/DefaultModuleFabric.h"
#include "../AssemblerLib/Core/Helper.h"

using namespace std;

int main(int argc, char* argv[])
{
    const uint8_t bitness = 16;
    DefaultModuleFabric<bitness> fabric;

    auto parser = fabric.get_parser_module();
    auto encode = fabric.get_code_module();
    auto sym_table = fabric.get_symbol_table();
    auto* path = "..\\AssemblerTests\\Tests\\Max.asm";
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

            if(helper::is_digit(symbol))
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
        case CommandType::l_command:
        {
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
