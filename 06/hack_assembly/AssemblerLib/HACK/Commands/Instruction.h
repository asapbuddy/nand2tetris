#pragma once
#include <string>

#include "../../API/Command.h"
#include "../../API/ICodeModule.h"

class Instruction : public Command
{
    std::string comp_, dest_, jump_;
    ICodeModule* code_module_ = nullptr;
public:
    ~Instruction() override = default;

    Instruction(std::string&& comp, string&& dest, string&& jump)
        : comp_(std::move(comp)),
          dest_(std::move(dest)),
          jump_(std::move(jump))
    {
        auto& fabric = FabricModule::get_instance();
        code_module_ = fabric.get_code_module();
    }

    std::string execute() override
    {
        std::bitset<16> mask(0);
        mask |= 0b111 << 13;
        mask |= std::bitset<16>(code_module_->comp(comp_));
        mask |= std::bitset<16>(code_module_->dest(dest_));
        mask |= std::bitset<16>(code_module_->jump(jump_));

        return mask.to_string();
    }
};
