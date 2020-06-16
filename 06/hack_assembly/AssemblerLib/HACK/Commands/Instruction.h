#pragma once
#include <string>


#include "InstructionDecoder.h"


class Instruction : public InstructionStatement
{
    std::string comp_, dest_, jump_, result_;
    InstructionDecoder* code_module_ = nullptr;
public:
    ~Instruction() override = default;

    Instruction(std::string&& comp, string&& dest, string&& jump)
        : comp_(comp), dest_(dest), jump_(jump)
    {
        auto& fabric = FabricModule::instance();
        code_module_ = fabric.get_code_module();
    }

    void Process() override
    {
        std::bitset<16> mask(0);
        mask |= 0b111 << 13;
        mask |= std::bitset<16>(code_module_->comp(comp_));
        mask |= std::bitset<16>(code_module_->dest(dest_));
        mask |= std::bitset<16>(code_module_->jump(jump_));

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
