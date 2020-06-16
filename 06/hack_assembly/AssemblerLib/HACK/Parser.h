#pragma once
#include <filesystem>
#include <fstream>
#include <iosfwd>


#include "../API/AssemblyParser.h"
#include "Commands/Address.h"
#include "Commands/Instruction.h"
#include "Commands/Label.h"
#include "Commands/NullCommand.h"

using namespace std;

class Parser final : public AssemblyParser
{
    ifstream FileStream_;
    string current_token_;
    StatementParameters& statement_parameters_;

public:
    Parser(ifstream&& filestream, StatementParameters& parameters)
        : FileStream_(std::move(filestream)),
          statement_parameters_(parameters)
    {
    }

    unique_ptr<Statement> ProduceStatement() override;

    void Advance() override;

    bool HasMoreCommands() override;

    ~Parser() override = default;
private:
    unique_ptr<NullCommand> ProduceNullCommand() const;
    unique_ptr<Address> ProduceAddressCommand(int start) const;
    unique_ptr<Instruction> ProduceInstructionCommand(int start) const;
    unique_ptr<Label> ProduceLabelCommand(int start) const;
};
