#pragma once
#include "../API/IParserModule.h"

class BaseParserModule : public IParserModule
{
public:
    bool init(char* path) override;
    bool has_more_commands() override;
    void advance() override;
    CommandType command_type() override;
    std::string symbol() override;
    std::bitset<16> dest() override;
    std::bitset<16> comp() override;
    std::bitset<16> jump() override;
    ~BaseParserModule() = default;
};
