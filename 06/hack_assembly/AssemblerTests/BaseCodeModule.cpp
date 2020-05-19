#include "../AssemblerLib/Modules/BaseCodeModule.h"

#include "../AssemblerLib/API/ICodeModule.h"
#include "gtest/gtest.h"

ICodeModule* module = new BaseCodeModule;

TEST(BaseCodeModule, CorrectJumpMnemonics)
{
    EXPECT_ANY_THROW(module->jump(""));
    ASSERT_EQ(module->jump("JGT"), bitset<3>("001"));
    ASSERT_EQ(module->jump("JEQ"), bitset<3>("010"));
    ASSERT_EQ(module->jump("JGE"), bitset<3>("011"));
    ASSERT_EQ(module->jump("JLT"), bitset<3>("100"));
    ASSERT_EQ(module->jump("JNE"), bitset<3>("101"));
    ASSERT_EQ(module->jump("JLE"), bitset<3>("110"));
    ASSERT_EQ(module->jump("JMP"), bitset<3>("111"));
}

TEST(BaseCodeModule, CorrectDestMnemonics)
{
    EXPECT_ANY_THROW(module->jump(""));
    ASSERT_EQ(module->dest("M"), bitset<3>("001"));
    ASSERT_EQ(module->dest("D"), bitset<3>("010"));
    ASSERT_EQ(module->dest("MD"), bitset<3>("011"));
    ASSERT_EQ(module->dest("A"), bitset<3>("100"));
    ASSERT_EQ(module->dest("AM"), bitset<3>("101"));
    ASSERT_EQ(module->dest("AD"), bitset<3>("110"));
    ASSERT_EQ(module->dest("AMD"), bitset<3>("111"));
}

TEST(BaseCodeModule, CorrectCompMnemonics)
{
    ASSERT_EQ(module->comp("0"), bitset<7>("0101010"));
    ASSERT_EQ(module->comp("1"), bitset<7>("0111111"));
    ASSERT_EQ(module->comp("-1"), bitset<7>("0111010"));
    ASSERT_EQ(module->comp("D"), bitset<7>("0001100"));
    ASSERT_EQ(module->comp("A"), bitset<7>("0110000"));
    ASSERT_EQ(module->comp("!D"), bitset<7>("0001101"));
    ASSERT_EQ(module->comp("!A"), bitset<7>("0110001"));
    ASSERT_EQ(module->comp("-D"), bitset<7>("0001111"));
    ASSERT_EQ(module->comp("-A"), bitset<7>("0110011"));
    ASSERT_EQ(module->comp("D+1"), bitset<7>("0011111"));
    ASSERT_EQ(module->comp("A+1"), bitset<7>("0110111"));
    ASSERT_EQ(module->comp("D-1"), bitset<7>("0001110"));
    ASSERT_EQ(module->comp("A-1"), bitset<7>("0110010"));
    ASSERT_EQ(module->comp("D+A"), bitset<7>("0000010"));
    ASSERT_EQ(module->comp("D-A"), bitset<7>("0010011"));
    ASSERT_EQ(module->comp("A-D"), bitset<7>("0000111"));
    ASSERT_EQ(module->comp("D&A"), bitset<7>("0000000"));
    ASSERT_EQ(module->comp("D|A"), bitset<7>("0010101"));

    // when a = 1
    ASSERT_EQ(module->comp("M"), bitset<7>("1110000"));
    ASSERT_EQ(module->comp("!M"), bitset<7>("1110001"));
    ASSERT_EQ(module->comp("-M"), bitset<7>("1110011"));
    ASSERT_EQ(module->comp("M+1"), bitset<7>("1110111"));
    ASSERT_EQ(module->comp("M-1"), bitset<7>("1110010"));
    ASSERT_EQ(module->comp("D+M"), bitset<7>("1000010"));
    ASSERT_EQ(module->comp("D-M"), bitset<7>("1010011"));
    ASSERT_EQ(module->comp("M-D"), bitset<7>("1000111"));
    ASSERT_EQ(module->comp("D&M"), bitset<7>("1000000"));
    ASSERT_EQ(module->comp("D|M"), bitset<7>("1010101"));
}
