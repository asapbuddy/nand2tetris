#include "BaseParserModule.h"

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

std::string BaseParserModule::dest()
{
    return "";
}

std::string BaseParserModule::comp()
{
    return "";
}

std::string BaseParserModule::jump()
{
    return "";
}
