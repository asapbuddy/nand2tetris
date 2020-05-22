#include "BaseParserModule.h"

bool BaseParserModule::init(char* path)
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
    return std::bitset<16>(0);
}

std::bitset<16> BaseParserModule::comp()
{
    return std::bitset<16>(0);
}

std::bitset<16> BaseParserModule::jump()
{
    return std::bitset<16>(0);
}
