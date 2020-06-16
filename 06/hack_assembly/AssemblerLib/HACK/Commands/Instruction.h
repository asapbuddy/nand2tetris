#pragma once
#include <string>


#include "InstructionDecoder.h"
#include "InstructionDto.h"


class Instruction : public Statement
{
    InstructionDto dto_;
    StatementParameters& parameters_;
    std::string result_;

public:
    ~Instruction() override = default;

    Instruction(InstructionDto&& dto, StatementParameters& parameters)
        : dto_(dto),
          parameters_(parameters)
    {
    }


    void Process() override
    {
        std::bitset<16> mask(0);
        mask |= 0b111 << 13;
        const auto decoder = parameters_.GetInstructionDecoder();

        if(dto_.comp.size())
            mask |= std::bitset<16>(decoder->comp(dto_.comp));
        if(dto_.dest.size())
            mask |= std::bitset<16>(decoder->dest(dto_.dest));
        if(dto_.jump.size())
            mask |= std::bitset<16>(decoder->jump(dto_.jump));

        result_ = mask.to_string();
    }

    string GetResult() override
    {
        return result_;
    }

    CommandType GetCommandType() override
    {
        return CommandType::c_command;
    }
};
