#pragma once
#include <filesystem>
#include <fstream>
#include <iosfwd>

#include "../API/ICodeModule.h"

using namespace std;

#include "../API/IParserModule.h"

class ParserModule final : public IParserModule
{
    ifstream file_stream_;
    CommandType current_type_;
    string dest_, comp_, jump_;
    ICommand* current_command_;

    string current_token_;
public:
    explicit ParserModule()
        : current_type_(CommandType::not_command),
          current_command_(nullptr)
    {
    }


    ICommand* get_command() override;
    void init(const char* file_path) override;
    void reset() override;
    bool advance() override;
    CommandType command_type() override;

    ~ParserModule() = default;
};
