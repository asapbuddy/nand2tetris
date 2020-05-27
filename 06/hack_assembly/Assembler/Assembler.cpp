#include <bitset>
#include <string>
#include <vector>

#include "../AssemblerLib/Core/DefaultModuleFabric.h"

using namespace std;

int main(int argc, char* argv[])
{
    DefaultModuleFabric<16> fabric;

    auto parser = fabric.get_parser_module();
    auto encode = fabric.get_code_module();
    auto sym_table = fabric.get_symbol_table();
    auto* path = "..\\AssemblerTests\\Tests\\Add.asm";
    if(!parser->init(path))
    {
        //TODO print error
    }

    std::vector<std::string> result;

    while(parser->has_more_commands())
    {
        parser->advance();
        const auto command_type = parser->command_type();
        switch(command_type)
        {
        case CommandType::a_command:
        {
            const auto symbol = parser->symbol();
            result.emplace_back(symbol);

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
