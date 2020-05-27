#include "BaseParserModule.h"

#include <bitset>
#include <string>

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

std::string BaseParserModule::dest()
{
    std::string current_sym{""};

    return code_module_->dest(current_sym);
}

std::string BaseParserModule::comp()
{
    std::string current_sym{""};

    return code_module_->comp(current_sym);
}

std::string BaseParserModule::jump()
{
    std::string current_sym{""};

    return code_module_->jump(current_sym);
}
