#pragma once
#include <string>


#include "InstructionParts.h"


class Instruction final : public Statement
{
    InstructionParts parts_;
    std::string result_;

public:
    ~Instruction() override = default;

    Instruction(InstructionParts&& dto)
        : parts_(dto)
    {
    }


    void Process(const StatementParameters& parameters) override
    {
        result_ = parameters.DecodeInstruction(parts_);
    }

    string GetResult() override
    {
        return result_;
    }

    CommandType GetCommandType() override
    {
        return CommandType::instruction;
    }
};
