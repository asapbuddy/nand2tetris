#pragma once
#include <filesystem>
#include <fstream>
#include <iosfwd>


#include "../API/AssemblerParser.h"
#include "Commands/Address.h"
#include "Commands/Instruction.h"
#include "Commands/Label.h"
#include "Commands/NullCommand.h"

using namespace std;

class Parser final : public AssemblerParser
{
    ifstream FileStream_;
    string current_token_;
    unsigned instructions_produced_;
    LookupTable* const symbol_table_;
    InstructionDecoder* const instruction_decoder_;

public:
    Parser(ifstream&& filestream, LookupTable* const lookup_table, InstructionDecoder* const instruction_decoder)
        : FileStream_(std::move(filestream)),
          instructions_produced_(0),
          symbol_table_(lookup_table),
          instruction_decoder_(instruction_decoder)

    {
    }

    unique_ptr<InstructionStatement> ProduceStatement() override;

    void Advance() override;

    bool HasMoreCommands() override;

    ~Parser() override = default;
private:
    unique_ptr<NullCommand> ProduceNullCommand() const;
    unique_ptr<Address> ProduceAddressCommand(int start) const;
    unique_ptr<Instruction> ProduceInstructionCommand(int start) const;
    unique_ptr<Label> ProduceLabelCommand(int start) const;
};
