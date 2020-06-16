#pragma once
#include "Decoder.h"

#include <bitset>


void Decoder::init_comp_table()
{
    comp_table_["0"] = "101010";
    comp_table_["1"] = "111111";
    comp_table_["-1"] = "111010";
    comp_table_["D"] = "001100";
    comp_table_["A"] = "110000";
    comp_table_["!D"] = "001101";
    comp_table_["!A"] = "110001";
    comp_table_["-D"] = "001111";
    comp_table_["-A"] = "110011";
    comp_table_["D+1"] = "011111";
    comp_table_["A+1"] = "110111";
    comp_table_["D-1"] = "001110";
    comp_table_["A-1"] = "110010";
    comp_table_["D+A"] = "000010";
    comp_table_["D-A"] = "010011";
    comp_table_["A-D"] = "000111";
    comp_table_["D&A"] = "000000";
    comp_table_["D|A"] = "010101";
    // when a =1
    comp_table_["M"] = "110000";
    comp_table_["!M"] = "110001";
    comp_table_["-M"] = "110011";
    comp_table_["M+1"] = "110111";
    comp_table_["M-1"] = "110010";
    comp_table_["D+M"] = "000010";
    comp_table_["D-M"] = "010011";
    comp_table_["M-D"] = "000111";
    comp_table_["D&M"] = "000000";
    comp_table_["D|M"] = "010101";
}


void Decoder::init_jump_table()
{
    jump_table_["JGT"] = "001";
    jump_table_["JEQ"] = "010";
    jump_table_["JGE"] = "011";
    jump_table_["JLT"] = "100";
    jump_table_["JNE"] = "101";
    jump_table_["JLE"] = "110";
    jump_table_["JMP"] = "111";
}


void Decoder::init_dest_table()
{
    dest_table_["M"] = "001";
    dest_table_["D"] = "010";
    dest_table_["MD"] = "011";
    dest_table_["A"] = "100";
    dest_table_["AM"] = "101";
    dest_table_["AD"] = "110";
    dest_table_["AMD"] = "111";
}


std::string Decoder::dest(std::string mnemonic)
{
    if(dest_table_.count(mnemonic) == 0)
        throw "Dest mnemonic not found";

    const auto result = bitset<16>(dest_table_[mnemonic]) << DEST_SHIFT;

    return result.to_string();
}


std::string Decoder::comp(std::string mnemonic)
{
    const bool a_bit = mnemonic.find('M') == string::npos ? false : true;
    string str;
    str += a_bit ? "1" : "0";
    if(comp_table_.count(mnemonic) == 0)
        throw "Comp mnemonic not found";
    str += comp_table_[mnemonic];

    const auto result = bitset<16>(str) << COMP_SHIFT;

    return result.to_string();
}


std::string Decoder::jump(std::string mnemonic)
{
    if(jump_table_.count(mnemonic) == 0)
        return bitset<16>(0).to_string();
    const auto result = bitset<16>(jump_table_[mnemonic]);
    return result.to_string();
}


std::string Decoder::instruction()
{
    std::string result{"111"};
    return result;
}
