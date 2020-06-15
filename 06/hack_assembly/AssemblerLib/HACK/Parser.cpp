﻿#include "Parser.h"

#include <string>
#include <filesystem>
#include <fstream>


#include "../API/AssemblerParser.h"
#include "../API/InstructionStatement.h"
#include "Commands/Address.h"
#include "Commands/Instruction.h"
#include "Commands/Label.h"

unique_ptr<InstructionStatement> Parser::ProduceCommand()
{
    return current_command_;
}

void Parser::init(const char* file_path)
{
    const filesystem::path input(file_path);
    if(!exists(input))
        throw ("Input file doesn't exist");

    if(!input.has_extension() || input.extension() != ".asm")
        throw ("Input file has unknown extension.\n Please use *.asm.");

    if(filesystem::is_empty(input))
        throw ("Input file is empty");

    file_stream_ = ifstream(input.c_str());
}


void Parser::Advance()
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

        if(token[i] == ' ' || token[i] == '/')
        {
            continue;
        }
        if(token[i] == '@')
        {
            while(token[i] != ' ' && i < token.size() - 1)
                ++i;

            current_token_ = token.substr(start + 1, i - start - (token[i] == ' ' ? 1 : 0));
            current_type_ = CommandType::a_command;

            current_command_ = new Address(std::move(current_token_));

            break;
        }
        if(token[i] == '(')
        {
            while(token[i] != ')' && i < token.size() - 1)
                ++i;
            current_token_ = token.substr(start + 1, i - start - 1);

            current_command_ = new Label(std::move(current_token_));
            current_type_ = CommandType::l_command;
            break;
        }
        else
        {
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
                jmp = token.substr(sc_pos + 1, i - sc_pos - (token[i] == ' ' ? 1 : 0));
            if(eq_pos > 0 && sc_pos < 0)
                comp = token.substr(eq_pos + 1, i - eq_pos - (token[i] == ' ' ? 1 : 0));
            if(eq_pos < 0 && sc_pos > 0)
                comp = token.substr(start, sc_pos - start);

            comp_ = comp;
            dest_ = dest;
            jump_ = jmp;

            current_command_ = new Instruction(
                std::move(comp),
                std::move(dest),
                std::move(jmp));
            break;
        }
    }
}

bool Parser::HasMoreCommands()
{
    return file_stream_.peek() != EOF;
}

CommandType Parser::GetCommandType()
{
    return current_type_;
}