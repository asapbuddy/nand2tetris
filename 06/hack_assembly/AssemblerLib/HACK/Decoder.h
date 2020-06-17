﻿#pragma once
#include <bitset>
#include <string>
#include <unordered_map>

#include "Statements/InstructionDecoder.h"


using namespace std;

class Decoder final : public InstructionDecoder
{
    std::unordered_map<string, string> comp_table_;
    std::unordered_map<string, string> jump_table_;
    std::unordered_map<string, string> dest_table_;

    const uint8_t DEST_SHIFT = 3;
    const uint8_t COMP_SHIFT = 6;

public:

    Decoder()
    {
        init_comp_table();
        init_jump_table();
        init_dest_table();
    }

    std::string decode(const PackedInstruction& instruction) override;

    ~Decoder() override = default;

private:

    void init_comp_table();
    void init_jump_table();
    void init_dest_table();

    bitset<16> dest(const string& mnemonic) const;
    bitset<16> comp(const string& mnemonic) const;
    bitset<16> jump(const string& mnemonic) const;
};
