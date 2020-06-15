#pragma once
#include <string>


#include "InstructionStatement.h"
#include "../../API/InstructionHandler.h"

class Instruction : public InstructionStatement
{
    std::string comp_, dest_, jump_;
    InstructionHandler* code_module_ = nullptr;
    std::string result_;
public:
    ~Instruction() override = default;

    Instruction(std::string&& comp, string&& dest, string&& jump)
        : comp_(std::move(comp)),
          dest_(std::move(dest)),
          jump_(std::move(jump))
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
};
