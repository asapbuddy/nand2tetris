#pragma once
#include <string>


#include "InstructionDecoder.h"
#include "PackedInstruction.h"


class Instruction final : public Statement
{
    PackedInstruction packed_;
    StatementParameters& parameters_;
    std::string result_;

public:
    ~Instruction() override = default;

    Instruction(PackedInstruction&& dto, StatementParameters& parameters)
        : packed_(dto),
          parameters_(parameters)
    {
    }


    void Process() override
    {
        auto decoder = parameters_.GetInstructionDecoder();
        result_ = decoder->decode(packed_);
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
