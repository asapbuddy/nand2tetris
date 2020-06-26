#pragma once
#include <filesystem>
#include <fstream>
#include <iosfwd>


#include "../API/Parser.h"
#include "Statements/Address.h"
#include "Statements/Instruction.h"
#include "Statements/Label.h"
#include "Statements/NullCommand.h"

using namespace std;

class AssemblyParser final : public Parser
{
    ifstream file_stream_;
    string current_token_;
    unsigned current_position_ = 0;

public:
    explicit AssemblyParser(ifstream&& ifs)
        : file_stream_(std::move(ifs))
    {
    }

    unique_ptr<Statement> ProduceStatement() override;

    void Advance() override;

    bool HasMoreCommands() override;

    ~AssemblyParser() override = default;
private:
    unique_ptr<NullCommand> ProduceNullCommand() const;
    unique_ptr<Address> ProduceAddressCommand() const;
    unique_ptr<Instruction> ProduceInstructionCommand() const;
    unique_ptr<Label> ProduceLabelCommand() const;
};
