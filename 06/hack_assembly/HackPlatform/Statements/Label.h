#pragma once

#include "../../API/Statement.h"

class Label final : public Statement
{
    std::string mnemonic_;
public:
    ~Label() override = default;

    explicit Label(string&& mnemonic)
        : mnemonic_(mnemonic)
    {
    }


    void Process(const StatementParameters& parameters) override
    {
        parameters.AddLabel(mnemonic_);
    }

    string GetResult() override
    {
        throw "I haven't result";
    }

    CommandType GetCommandType() override
    {
        return CommandType::label;
    }
};
