#pragma once

#include "../../API/Statement.h"

class NullCommand final : public Statement
{
public:
    ~NullCommand() override = default;

    void Process(const Context&) override;

    string GetResult() override;

    CommandType GetCommandType() override;
};
