#pragma once
#include <filesystem>
#include <fstream>
#include <iosfwd>
#include <sstream>

using namespace std;

#include "../API/ICodeModule.h"
#include "../API/IParserModule.h"

class BaseParserModule final : public IParserModule
{
    ICodeModule* code_module_;
    ifstream file_stream_;
    CommandType current_type_;

    string current_token_;
public:
    explicit BaseParserModule(ICodeModule* module)
        : code_module_(module), current_type_(CommandType::not_command)
    {
    }


    bool init(const char* file_path) override;
    bool has_more_commands() override;
    void advance() override;
    CommandType command_type() override;
    std::string symbol() override;
    std::string dest() override;
    std::string comp() override;
    std::string jump() override;
    ~BaseParserModule() = default;
};
