#include "Parser.h"

#include <string>
#include <filesystem>
#include <fstream>

#include "Commands/Address.h"
#include "Commands/Instruction.h"
#include "Commands/Label.h"


void Parser::Advance()
{
    do
    {
        std::getline(FileStream_, current_token_);
    }
    while(FileStream_.is_open() && current_token_.size() == 0 || current_token_[0] == '/');
}

bool Parser::HasMoreCommands()
{
    //TODO: Figure out to is need more intillegence method to determine that or not
    return FileStream_.peek() != EOF;
}


unique_ptr<Statement> Parser::ProduceStatement()
{
    const string& token = current_token_;
    unique_ptr<Statement> result;

    for(int i = 0; i < token.size() - 1; ++i)
    {
        if(token[i] == ' ')
            continue;

        if(token[i] == '/')
        {
            result = ProduceNullCommand();
            break;
        }
        if(token[i] == '@')
        {
            result = ProduceAddressCommand(i);
            break;
        }
        if(token[i] == '(')
        {
            result = ProduceLabelCommand(i);
            break;
        }
        else
        {
            result = ProduceInstructionCommand(i);
            break;
        }
    }

    const auto command_type = result->GetCommandType();
    if(command_type == CommandType::a_command || command_type == CommandType::c_command)
        statement_parameters_.IncreaseInstructionCounter();

    return result;
}

unique_ptr<NullCommand> Parser::ProduceNullCommand() const
{
    return make_unique<NullCommand>();
}

unique_ptr<Address> Parser::ProduceAddressCommand(int start) const
{
    const string& token = current_token_;
    int i = start;
    while(token[i] != ' '
          && token[i] != '\n'
          && i < token.size() - 1)
        ++i;

    auto mnemonic = token.substr(start + 1, i - start - (token[i] == ' ' ? 1 : 0));
    return make_unique<Address>(std::move(mnemonic), statement_parameters_);
}

unique_ptr<Instruction> Parser::ProduceInstructionCommand(int start) const
{
    string dest, comp, jump;
    const string& token = current_token_;

    int i = start, eq_pos = -1, sc_pos = -1; // equal and semicolon

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
        jump = token.substr(sc_pos + 1, i - sc_pos - (token[i] == ' ' ? 1 : 0));
    if(eq_pos > 0 && sc_pos < 0)
        comp = token.substr(eq_pos + 1, i - eq_pos - (token[i] == ' ' ? 1 : 0));
    if(eq_pos < 0 && sc_pos > 0)
        comp = token.substr(start, sc_pos - start);

    InstructionDto dto{dest, comp, jump};

    return make_unique<Instruction>(std::move(dto), statement_parameters_);
}

unique_ptr<Label> Parser::ProduceLabelCommand(int start) const
{
    int i = start;
    while(current_token_[i] != ')' && i < current_token_.size() - 1)
        ++i;
    auto mnemonic = current_token_.substr(start + 1, i - start - 1);
    return make_unique<Label>(move(mnemonic), statement_parameters_);
}
