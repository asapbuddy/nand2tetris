#pragma once
#include <filesystem>
#include <fstream>
#include <iosfwd>

#include "../API/AssemblerParser.h"

using namespace std;

class Parser final : public AssemblerParser
{
    ifstream file_stream_;
    CommandType current_type_ = CommandType::not_command;
    string dest_, comp_, jump_;
    unique_ptr<InstructionStatement> current_command_;
    string current_token_;

public:
    Parser() = default;

    unique_ptr<InstructionStatement> ProduceCommand() override;

    void Advance() override;

    bool HasMoreCommands() override;

    CommandType GetCommandType() override;

    ~Parser() override = default;
};
