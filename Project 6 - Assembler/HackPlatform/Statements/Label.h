#pragma once

#include "../../API/Statement.h"

class Label final : public Statement
{
    std::string mnemonic_;
public:
    ~Label() override;

    explicit Label(string&& mnemonic);

    void Process(const Context& parameters) override;

    string GetResult() override;

    CommandType GetCommandType() override;
};
