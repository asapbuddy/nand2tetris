﻿#pragma once
#include <filesystem>
#include <fstream>
#include <iosfwd>


#include "../API/AssemblyParser.h"
#include "Statements/Address.h"
#include "Statements/Instruction.h"
#include "Statements/Label.h"
#include "Statements/NullCommand.h"

using namespace std;

class Parser final : public AssemblyParser
{
    ifstream FileStream_;
    string current_token_;
    unsigned current_position_ = 0;

public:
    Parser(ifstream&& filestream)
        : FileStream_(std::move(filestream))
    {
    }

    unique_ptr<Statement> ProduceStatement(StatementParameters& statement_parameters) override;

    void Advance() override;

    bool HasMoreCommands() override;

    ~Parser() override = default;
private:
    unique_ptr<NullCommand> ProduceNullCommand() const;
    unique_ptr<Address> ProduceAddressCommand(StatementParameters& statement_parameters) const;
    unique_ptr<Instruction> ProduceInstructionCommand(StatementParameters& statement_parameters) const;
    unique_ptr<Label> ProduceLabelCommand(StatementParameters& statement_parameters) const;
};
