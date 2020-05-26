#include <boost/test/unit_test.hpp>

#include "Fixtures.h"
#include <bitset>
using namespace std;

namespace assembler_tests
{
    BOOST_FIXTURE_TEST_SUITE(ModulesTests, Configuration)

        BOOST_AUTO_TEST_SUITE(BaseCodeModule)

            BOOST_AUTO_TEST_CASE(CorrectJumpMnemonics)
            {
                BOOST_TEST(code_module.jump("JGT")== bitset<3>("001"));
                BOOST_TEST(code_module.jump("JEQ")== bitset<3>("010"));
                BOOST_TEST(code_module.jump("JGE")== bitset<3>("011"));
                BOOST_TEST(code_module.jump("JLT")== bitset<3>("100"));
                BOOST_TEST(code_module.jump("JNE")== bitset<3>("101"));
                BOOST_TEST(code_module.jump("JLE")== bitset<3>("110"));
                BOOST_TEST(code_module.jump("JMP")== bitset<3>("111"));
            }

            BOOST_AUTO_TEST_CASE(CorrectDestMnemonics)
            {
                BOOST_TEST(code_module.dest("M")== bitset<3>("001"));
                BOOST_TEST(code_module.dest("D")== bitset<3>("010"));
                BOOST_TEST(code_module.dest("MD")== bitset<3>("011"));
                BOOST_TEST(code_module.dest("A")== bitset<3>("100"));
                BOOST_TEST(code_module.dest("AM")== bitset<3>("101"));
                BOOST_TEST(code_module.dest("AD")== bitset<3>("110"));
                BOOST_TEST(code_module.dest("AMD")== bitset<3>("111"));
            }

            BOOST_AUTO_TEST_CASE(CorrectCompMnemonics)
            {
                BOOST_TEST(code_module.comp("0")== bitset<7>("0101010"));
                BOOST_TEST(code_module.comp("1")== bitset<7>("0111111"));
                BOOST_TEST(code_module.comp("-1")== bitset<7>("0111010"));
                BOOST_TEST(code_module.comp("D")== bitset<7>("0001100"));
                BOOST_TEST(code_module.comp("A")== bitset<7>("0110000"));
                BOOST_TEST(code_module.comp("!D")== bitset<7>("0001101"));
                BOOST_TEST(code_module.comp("!A")== bitset<7>("0110001"));
                BOOST_TEST(code_module.comp("-D")== bitset<7>("0001111"));
                BOOST_TEST(code_module.comp("-A")== bitset<7>("0110011"));
                BOOST_TEST(code_module.comp("D+1")== bitset<7>("0011111"));
                BOOST_TEST(code_module.comp("A+1")== bitset<7>("0110111"));
                BOOST_TEST(code_module.comp("D-1")== bitset<7>("0001110"));
                BOOST_TEST(code_module.comp("A-1")== bitset<7>("0110010"));
                BOOST_TEST(code_module.comp("D+A")== bitset<7>("0000010"));
                BOOST_TEST(code_module.comp("D-A")== bitset<7>("0010011"));
                BOOST_TEST(code_module.comp("A-D")== bitset<7>("0000111"));
                BOOST_TEST(code_module.comp("D&A")== bitset<7>("0000000"));
                BOOST_TEST(code_module.comp("D|A")== bitset<7>("0010101"));

                // when a = 1
                BOOST_TEST(code_module.comp("M")== bitset<7>("1110000"));
                BOOST_TEST(code_module.comp("!M")== bitset<7>("1110001"));
                BOOST_TEST(code_module.comp("-M")== bitset<7>("1110011"));
                BOOST_TEST(code_module.comp("M+1")== bitset<7>("1110111"));
                BOOST_TEST(code_module.comp("M-1")== bitset<7>("1110010"));
                BOOST_TEST(code_module.comp("D+M")== bitset<7>("1000010"));
                BOOST_TEST(code_module.comp("D-M")== bitset<7>("1010011"));
                BOOST_TEST(code_module.comp("M-D")== bitset<7>("1000111"));
                BOOST_TEST(code_module.comp("D&M")== bitset<7>("1000000"));
                BOOST_TEST(code_module.comp("D|M")== bitset<7>("1010101"));
            }

            BOOST_AUTO_TEST_CASE(CorrectBitsOperation)
            {
        
        
            }

        BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE_END()
} // namespace tests
