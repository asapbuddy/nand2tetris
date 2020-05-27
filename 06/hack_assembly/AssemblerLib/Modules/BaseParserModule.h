#pragma once
#include "../API/ICodeModule.h"
#include "../API/IParserModule.h"

class BaseParserModule final : public IParserModule
{
    ICodeModule* code_module_;
public:
    explicit BaseParserModule(ICodeModule* module)
        : code_module_(module)
    {
    }

    
    BaseParserModule():code_module_(nullptr) {  }
    bool init(const char* path) override;
    bool has_more_commands() override;
    void advance() override;
    CommandType command_type() override;
    std::string symbol() override;
    std::string dest() override;
    std::string comp() override;
    std::string jump() override;
    ~BaseParserModule() = default;
};
