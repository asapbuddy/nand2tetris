﻿#pragma once
#include "../../API/Statement.h"

class NullCommand : public Statement
{
public:
    void Process() override
    {
    }

    string GetResult() override
    {
        return "You're done.";
    }

    CommandType GetCommandType() override
    {
        return CommandType::not_command;
    }
};
