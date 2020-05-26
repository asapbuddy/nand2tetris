#include "BaseParserModule.h"

#include <bitset>

bool BaseParserModule::init(const char* path)
{
    return true;
}

bool BaseParserModule::has_more_commands()
{
    return false;
}

void BaseParserModule::advance()
{
}

CommandType BaseParserModule::command_type()
{
    return CommandType::a_command;
}

std::string BaseParserModule::symbol()
{
    return "";
}

std::bitset<16> BaseParserModule::dest()
{
    std::bitset<16> dest(0);

    return dest;
}

std::bitset<16> BaseParserModule::comp()
{
    std::bitset<16> comp(0);
    bool a_flag = true;
    comp |= a_flag ? 1 << 12 : 0 << 12;
    return comp;
}

std::bitset<16> BaseParserModule::jump()
{
    std::bitset<16> jump("");

    return jump;
}
