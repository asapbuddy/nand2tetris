#pragma once
#include <string>


#include "InstructionDecoder.h"
#include "InstructionDto.h"


class Instruction : public InstructionStatement
{
    InstructionDto dto_;
    InstructionDecoder* const code_module_;
    std::string result_;
public:
    ~Instruction() override = default;

    Instruction(InstructionDto&& dto, InstructionDecoder* const decoder)
        : dto_(dto), code_module_(decoder)
    {
    }


    void Process() override
    {
        std::bitset<16> mask(0);
        mask |= 0b111 << 13;

        if(dto_.comp.size())
            mask |= std::bitset<16>(code_module_->comp(dto_.comp));
        if(dto_.dest.size())
            mask |= std::bitset<16>(code_module_->dest(dto_.dest));
        if(dto_.jump.size())
            mask |= std::bitset<16>(code_module_->jump(dto_.jump));

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
