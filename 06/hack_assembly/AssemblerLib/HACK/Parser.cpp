#include "Parser.h"

#include <string>
#include <filesystem>
#include <fstream>

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


unique_ptr<Statement> Parser::ProduceStatement(StatementParameters& statement_parameters)
{
    current_position_ = 0;
    const auto& token = current_token_;
    auto& position = current_position_;
    while(token.at(position) == ' ')
        ++position;

    if(token[position] == '/')
        return ProduceNullCommand();
    if(token[position] == '@')
        return ProduceAddressCommand(statement_parameters);
    if(token[position] == '(')
        return ProduceLabelCommand(statement_parameters);

    return ProduceInstructionCommand(statement_parameters);
}

unique_ptr<NullCommand> Parser::ProduceNullCommand() const
{
    return make_unique<NullCommand>();
}

unique_ptr<Address> Parser::ProduceAddressCommand(StatementParameters& statement_parameters) const
{
    const auto& token = current_token_;
    const auto& start = current_position_;
    auto i = start;

    while(token[i] != ' '
          && token[i] != '\n'
          && i < token.size() - 1)
        ++i;

    auto mnemonic = token.substr(start + 1, i - start - (token[i] == ' ' ? 1 : 0));
    return make_unique<Address>(std::move(mnemonic), statement_parameters);
}

unique_ptr<Instruction> Parser::ProduceInstructionCommand(StatementParameters& statement_parameters) const
{
    string dest, comp, jump;
    const auto& token = current_token_;
    const auto& start = current_position_;

    auto i = start;
    auto eq_pos = -1, sc_pos = -1; // equal and semicolon

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

    PackedInstruction packed_instruction{dest, comp, jump};

    return make_unique<Instruction>(std::move(packed_instruction), statement_parameters);
}

unique_ptr<Label> Parser::ProduceLabelCommand(StatementParameters& statement_parameters) const
{
    const auto& start = current_position_;
    auto i = start;
    while(current_token_[i] != ')' && i < current_token_.size() - 1)
        ++i;
    auto mnemonic = current_token_.substr(start + 1, i - start - 1);
    return make_unique<Label>(move(mnemonic), statement_parameters);
}
