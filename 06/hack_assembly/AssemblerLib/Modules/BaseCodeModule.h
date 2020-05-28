﻿#pragma once
#include <string>
#include <unordered_map>

#include "../API/ICodeModule.h"

using namespace std;

template <uint8_t Bits>
class BaseCodeModule final : public ICodeModule
{
    std::unordered_map<string, string> comp_table_;
    std::unordered_map<string, string> jump_table_;
    std::unordered_map<string, string> dest_table_;

    const uint8_t DEST_SHIFT = 3;
    const uint8_t COMP_SHIFT = 6;

    void init_comp_table();
    void init_jump_table();
    void init_dest_table();
public:

    BaseCodeModule()
    {
        init_comp_table();
        init_jump_table();
        init_dest_table();
    }

    std::string dest(std::string mnemonic) override;
    std::string comp(std::string mnemonic) override;
    std::string jump(std::string mnemonic) override;
    std::string instruction() override;
};

#include "BaseCodeModule.inl"
