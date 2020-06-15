#pragma once
#include "../../API/InstructionStatement.h"

class NullCommand : public InstructionStatement
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
