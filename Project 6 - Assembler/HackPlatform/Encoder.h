﻿#pragma once
#include <bitset>
#include <string>
#include <unordered_map>

#include "../API/InstructionEncoder.h"

using namespace std;

class Encoder final : public InstructionEncoder
{
    std::unordered_map<string, string> comp_table_;
    std::unordered_map<string, string> jump_table_;
    std::unordered_map<string, string> dest_table_;

    const uint8_t dest_shift_ = 3;
    const uint8_t comp_shift_ = 6;

public:

    Encoder()
    {
        init_comp_table();
        init_jump_table();
        init_dest_table();
    }

    std::string Encode(const InstructionParts& instruction) override;

    ~Encoder() override = default;

private:

    void init_comp_table();
    void init_jump_table();
    void init_dest_table();

    bitset<16> dest(const string& mnemonic) const;
    bitset<16> comp(const string& mnemonic) const;
    bitset<16> jump(const string& mnemonic) const;
};
