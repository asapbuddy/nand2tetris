#pragma once
#include "../API/IParserModule.h"

class BaseParserModule : public IParserModule
{
public:
    bool has_more_commands() override;
    void advance() override;
    CommandType command_type() override;
    std::string symbol() override;
    std::string dest() override;
    std::string comp() override;
    std::string jump() override;
};
