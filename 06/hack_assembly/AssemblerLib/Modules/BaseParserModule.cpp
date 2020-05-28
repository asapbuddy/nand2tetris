#include "BaseParserModule.h"

#include <bitset>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>

#include "../Core/Helper.h"

bool BaseParserModule::init(const char* file_path)
{
    const filesystem::path input(file_path);
    if(!exists(input))
        throw ("Input file doesn't exist");

    if(!input.has_extension() || input.extension() != ".asm")
        throw ("Input file has unknown extension.\n Please use *.asm.");

    if(filesystem::is_empty(input))
        throw ("Input file is empty");

    file_stream_ = ifstream(input.c_str());
    return true;
}

bool BaseParserModule::has_more_commands()
{
    return file_stream_.peek() != EOF;
}

void BaseParserModule::advance()
{
    std::string token;
    do
    {
        std::getline(file_stream_, token);
    }
    while(file_stream_.is_open() && token.size() == 0 || token[0] == '/');

    switch(token[0])
    {
    case '@':
        current_type_ = CommandType::a_command;
        break;
    case '(':
        current_type_ = CommandType::l_command;
        break;
    default:
        current_type_ = CommandType::c_command;
        break;
    }
    helper::remove_comment(token);
    helper::trim(token);
    current_token_ = token;
}

CommandType BaseParserModule::command_type()
{
    return current_type_;
}

std::string BaseParserModule::symbol()
{
    if(current_type_ == CommandType::a_command)
    {
        return current_token_.substr(1);
    }
    if(current_type_ == CommandType::l_command)
    {
        return current_token_.substr(1, current_token_.length() - 1);
    }
    throw "Current command nor A nor L";
}

std::string BaseParserModule::dest()
{
    std::string sym;
    auto splitted = helper::split(current_token_, '=');
    if(splitted.size() > 1)
        sym = splitted[0];

    return code_module_->dest(sym);
}

std::string BaseParserModule::comp()
{
    string sym;
    string comp_temp;

    // dirty
    if(stoi(this->dest()) > 0)
    {
        comp_temp = helper::split(current_token_)
        //auto splitted = helper::split()
    }
    else
    {
    }

    return sym; //code_module_->comp(current_sym);
}

std::string BaseParserModule::jump()
{
    std::string current_sym{""};

    return code_module_->jump(current_sym);
}
