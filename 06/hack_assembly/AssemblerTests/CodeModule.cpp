#include <boost/test/unit_test.hpp>

#include "Fixtures.h"
#include <bitset>
using namespace std;

constexpr uint8_t BITNESS = 16;
constexpr uint8_t COMP_SHIFT = 6;
constexpr uint8_t DEST_SHIFT = 3;

namespace assembler_tests
{
    BOOST_FIXTURE_TEST_SUITE(ModulesTests, Configuration)

        BOOST_AUTO_TEST_SUITE(BaseCodeModule)

            BOOST_AUTO_TEST_CASE(CorrectJumpMnemonics)
            {
                const auto JGT = bitset<BITNESS>("001").to_string();
                const auto JEQ = bitset<BITNESS>("010").to_string();
                const auto JGE = bitset<BITNESS>("011").to_string();
                const auto JLT = bitset<BITNESS>("100").to_string();
                const auto JNE = bitset<BITNESS>("101").to_string();
                const auto JLE = bitset<BITNESS>("110").to_string();
                const auto JMP = bitset<BITNESS>("111").to_string();

                BOOST_TEST(code_module.jump("JGT")== JGT);
                BOOST_TEST(code_module.jump("JEQ")== JEQ);
                BOOST_TEST(code_module.jump("JGE")== JGE);
                BOOST_TEST(code_module.jump("JLT")== JLT);
                BOOST_TEST(code_module.jump("JNE")== JNE);
                BOOST_TEST(code_module.jump("JLE")== JLE);
                BOOST_TEST(code_module.jump("JMP")== JMP);
            }

            BOOST_AUTO_TEST_CASE(CorrectDestMnemonics)
            {
                const auto b_M = bitset<BITNESS>("001") << DEST_SHIFT;
                const auto b_D = bitset<BITNESS>("010") << DEST_SHIFT;
                const auto b_MD = bitset<BITNESS>("011") << DEST_SHIFT;
                const auto b_A = bitset<BITNESS>("100") << DEST_SHIFT;
                const auto b_AM = bitset<BITNESS>("101") << DEST_SHIFT;
                const auto b_AD = bitset<BITNESS>("110") << DEST_SHIFT;
                const auto b_AMD = bitset<BITNESS>("111") << DEST_SHIFT;

                BOOST_TEST(code_module.dest("M")== b_M.to_string());
                BOOST_TEST(code_module.dest("D")== b_D.to_string());
                BOOST_TEST(code_module.dest("MD")== b_MD.to_string());
                BOOST_TEST(code_module.dest("A")== b_A.to_string());
                BOOST_TEST(code_module.dest("AM")== b_AM.to_string());
                BOOST_TEST(code_module.dest("AD")== b_AD.to_string());
                BOOST_TEST(code_module.dest("AMD")== b_AMD.to_string());
            }

            BOOST_AUTO_TEST_CASE(CorrectCompMnemonics)
            {
                const auto zero = bitset<BITNESS>("0101010") << COMP_SHIFT;
                const auto one = bitset<BITNESS>("0111111") << COMP_SHIFT;
                const auto nOne = bitset<BITNESS>("0111010") << COMP_SHIFT;
                const auto D = bitset<BITNESS>("0001100") << COMP_SHIFT;
                const auto A = bitset<BITNESS>("0110000") << COMP_SHIFT;
                const auto nD = bitset<BITNESS>("0001101") << COMP_SHIFT;
                const auto nA = bitset<BITNESS>("0110001") << COMP_SHIFT;
                const auto negD = bitset<BITNESS>("0001111") << COMP_SHIFT;
                const auto negA = bitset<BITNESS>("0110011") << COMP_SHIFT;
                const auto Dp1 = bitset<BITNESS>("0011111") << COMP_SHIFT;
                const auto Ap1 = bitset<BITNESS>("0110111") << COMP_SHIFT;
                const auto Dm1 = bitset<BITNESS>("0001110") << COMP_SHIFT;
                const auto Am1 = bitset<BITNESS>("0110010") << COMP_SHIFT;
                const auto DpA = bitset<BITNESS>("0000010") << COMP_SHIFT;
                const auto DmA = bitset<BITNESS>("0010011") << COMP_SHIFT;
                const auto AmD = bitset<BITNESS>("0000111") << COMP_SHIFT;
                const auto DandA = bitset<BITNESS>("0000000") << COMP_SHIFT;
                const auto DorA = bitset<BITNESS>("0010101") << COMP_SHIFT;

                const auto M = bitset<BITNESS>("1110000") << COMP_SHIFT;
                const auto nM = bitset<BITNESS>("1110001") << COMP_SHIFT;
                const auto negM = bitset<BITNESS>("1110011") << COMP_SHIFT;
                const auto Mp1 = bitset<BITNESS>("1110111") << COMP_SHIFT;
                const auto Mm1 = bitset<BITNESS>("1110010") << COMP_SHIFT;
                const auto DpM = bitset<BITNESS>("1000010") << COMP_SHIFT;
                const auto DmM = bitset<BITNESS>("1010011") << COMP_SHIFT;
                const auto MmD = bitset<BITNESS>("1000111") << COMP_SHIFT;
                const auto DandM = bitset<BITNESS>("1000000") << COMP_SHIFT;
                const auto DorM = bitset<BITNESS>("1010101") << COMP_SHIFT;
        
                BOOST_TEST(code_module.comp("0")== zero.to_string());
                BOOST_TEST(code_module.comp("1")== one.to_string());
                BOOST_TEST(code_module.comp("-1")== nOne.to_string());
                BOOST_TEST(code_module.comp("D")== D.to_string());
                BOOST_TEST(code_module.comp("A")== A.to_string());
                BOOST_TEST(code_module.comp("!D")== nD.to_string());
                BOOST_TEST(code_module.comp("!A")== nA.to_string());
                BOOST_TEST(code_module.comp("-D")== negD.to_string());
                BOOST_TEST(code_module.comp("-A")== negA.to_string());
                BOOST_TEST(code_module.comp("D+1")== Dp1.to_string());
                BOOST_TEST(code_module.comp("A+1")== Ap1.to_string());
                BOOST_TEST(code_module.comp("D-1")== Dm1.to_string());
                BOOST_TEST(code_module.comp("A-1")== Am1.to_string());
                BOOST_TEST(code_module.comp("D+A")== DpA.to_string());
                BOOST_TEST(code_module.comp("D-A")== DmA.to_string());
                BOOST_TEST(code_module.comp("A-D")== AmD.to_string());
                BOOST_TEST(code_module.comp("D&A")== DandA.to_string());
                BOOST_TEST(code_module.comp("D|A")== DorA.to_string());

                BOOST_TEST(code_module.comp("M")== M.to_string());
                BOOST_TEST(code_module.comp("!M")== nM.to_string());
                BOOST_TEST(code_module.comp("-M")== negM.to_string());
                BOOST_TEST(code_module.comp("M+1")== Mp1.to_string());
                BOOST_TEST(code_module.comp("M-1")== Mm1.to_string());
                BOOST_TEST(code_module.comp("D+M")== DpM.to_string());
                BOOST_TEST(code_module.comp("D-M")== DmM.to_string());
                BOOST_TEST(code_module.comp("M-D")== MmD.to_string());
                BOOST_TEST(code_module.comp("D&M")== DandM.to_string());
                BOOST_TEST(code_module.comp("D|M")== DorM.to_string());
            }

        BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE_END()
} // namespace tests
