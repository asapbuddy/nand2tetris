#include "BaseParserModule.h"

#include <bitset>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>


#include "../API/IParserModule.h"
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
    dest_ = "", comp_ = "", jump_ = "";
    std::string token;
    do
    {
        std::getline(file_stream_, token);
    }
    while(file_stream_.is_open() && token.size() == 0 || token[0] == '/');

    for(int i = 0; i < token.size() - 1; ++i)
    {
        int start = i;

        if(token[i] == ' ')
        {
            continue;
        }
        if(token[i] == '/')
        {
            current_type_ = CommandType::not_command;
            break;
        }
        if(token[i] == '@')
        {
            while(token[i] != ' ' && i < token.size() - 1)
                ++i;
            current_token_ = token.substr(start + 1, i - start - (token[i]==' '?1:0));
            current_type_ = CommandType::a_command;
            break;
        }
        if(token[i] == '(')
        {
            while(token[i] != ')' && i < token.size() - 1)
                ++i;
            current_token_ = token.substr(start + 1, i - start - 1);
            current_type_ = CommandType::l_command;
            break;
        }
        string dest, comp, jmp;
        int eq_pos = -1, sc_pos = -1; // equal and semicolon
        current_type_ = CommandType::c_command;
        while(i < token.size() - 1 && token[i] != ' ')
        {
            if(token[i] == '=')
                eq_pos = i;

            if(token[i] == ';')
                sc_pos = i;

            ++i;
        }

        if(eq_pos > 0)
            dest = token.substr(start, eq_pos - start);
        if(sc_pos > 0)
            jmp = token.substr(sc_pos+1, i - sc_pos-1);
        if(eq_pos > 0 && sc_pos < 0)
            comp = token.substr(eq_pos + 1, i - eq_pos-1);
        if(eq_pos < 0 && sc_pos > 0)
            comp = token.substr(start, sc_pos - start);

        comp_ = comp;
        dest_ = dest;
        jump_ = jmp;
        break;
    }
}

CommandType BaseParserModule::command_type()
{
    return current_type_;
}

std::string BaseParserModule::symbol()
{
    if(current_type_ == CommandType::a_command || current_type_ == CommandType::l_command)
    {
        return current_token_;
    }
    throw "Current command nor A nor L";
}

std::string BaseParserModule::dest()
{
    if(current_type_ != CommandType::c_command)
        throw "Current command not C";

    return code_module_->dest(dest_);
}

std::string BaseParserModule::comp()
{
    if(current_type_ != CommandType::c_command)
        throw "Current command not C";

    return code_module_->comp(comp_);
}

std::string BaseParserModule::jump()
{
    if(current_type_ != CommandType::c_command)
        throw "Current command not C";

    return code_module_->jump(jump_);
}
