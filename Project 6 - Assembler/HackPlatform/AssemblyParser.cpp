#include "AssemblyParser.h"

#include <string>
#include <filesystem>
#include <fstream>

void AssemblyParser::Advance()
{
    do
    {
        std::getline(file_stream_, current_token_);
    }
    while(file_stream_.is_open() && current_token_.size() == 0 || current_token_[0] == '/');
}

bool AssemblyParser::HasMoreCommands()
{
    return file_stream_.peek() != EOF;
}


unique_ptr<Statement> AssemblyParser::ProduceStatement()
{
    current_position_ = 0;
    const auto& token = current_token_;
    auto& position = current_position_;
    while(token.at(position) == ' ')
        ++position;

    if(token[position] == '/')
        return ProduceNullCommand();
    if(token[position] == '@')
        return ProduceAddressCommand();
    if(token[position] == '(')
        return ProduceLabelCommand();

    return ProduceInstructionCommand();
}

unique_ptr<NullCommand> AssemblyParser::ProduceNullCommand() const
{
    return make_unique<NullCommand>();
}

unique_ptr<Address> AssemblyParser::ProduceAddressCommand() const
{
    const auto& token = current_token_;
    const auto& start = current_position_;
    auto i = start;

    while(token[i] != ' '
          && token[i] != '\n'
          && i < token.size() - 1)
        ++i;

    auto mnemonic = token.substr(start + 1, i - start - (token[i] == ' ' ? 1 : 0));
    return make_unique<Address>(std::move(mnemonic));
}

unique_ptr<Instruction> AssemblyParser::ProduceInstructionCommand() const
{
    string dest, comp, jump;
    const auto& token = current_token_;
    const auto& start = current_position_;

    auto i = start;
    auto eqPos = -1, scPos = -1; // equal and semicolon

    while(i < token.size() - 1 && token[i] != ' ')
    {
        if(token[i] == '=')
            eqPos = i;

        if(token[i] == ';')
            scPos = i;
        ++i;
    }

    if(eqPos > 0)
        dest = token.substr(start, eqPos - start);
    if(scPos > 0)
        jump = token.substr(scPos + 1, i - scPos - (token[i] == ' ' ? 1 : 0));
    if(eqPos > 0 && scPos < 0)
        comp = token.substr(eqPos + 1, i - eqPos - (token[i] == ' ' ? 1 : 0));
    if(eqPos < 0 && scPos > 0)
        comp = token.substr(start, scPos - start);

    InstructionParts packedInstruction{dest, comp, jump};

    return make_unique<Instruction>(std::move(packedInstruction));
}

unique_ptr<Label> AssemblyParser::ProduceLabelCommand() const
{
    const auto& start = current_position_;
    auto i = start;
    while(current_token_[i] != ')' && i < current_token_.size() - 1)
        ++i;
    auto mnemonic = current_token_.substr(start + 1, i - start - 1);
    return make_unique<Label>(move(mnemonic));
}
