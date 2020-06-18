#pragma once
#include "../../API/Statement.h"

class NullCommand final : public Statement
{
public:

    void Process(const StatementParameters&) override
    {
        throw "Attempt to processing NullCommand";
    }


    string GetResult() override
    {
        throw "Attempt to get result of NullCommand processing";
    }

    CommandType GetCommandType() override
    {
        return CommandType::not_command;
    }
};
