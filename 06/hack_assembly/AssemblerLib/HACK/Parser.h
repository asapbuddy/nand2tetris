#pragma once
#include <filesystem>
#include <fstream>
#include <iosfwd>

#include "../API/IParserModule.h"

using namespace std;

class Parser final : public IParserModule
{
    ifstream file_stream_;
    CommandType current_type_ = CommandType::not_command;
    string dest_, comp_, jump_;
    Command* current_command_ = nullptr;
    string current_token_;

public:
    Parser() = default;

    Command* get_command() override;
    void init(const char* file_path) override;
    void reset() override;
    bool advance() override;
    CommandType command_type() override;

    ~Parser() override = default;
};
