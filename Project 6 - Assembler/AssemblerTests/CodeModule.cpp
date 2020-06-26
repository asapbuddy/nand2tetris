// ReSharper disable CppInconsistentNaming
#include <boost/test/unit_test.hpp>

#include "Fixtures.h"
#include <bitset>

#include "Project 6 - Assembler/HackPlatform/Encoder.h"

using namespace std;

constexpr uint8_t BITNESS = 16;
constexpr uint8_t COMP_SHIFT = 6;
constexpr uint8_t DEST_SHIFT = 3;

namespace assembler_tests
{
    BOOST_FIXTURE_TEST_SUITE(ModulesTests, Configuration)

        BOOST_AUTO_TEST_SUITE(BaseCodeModuleTest)

            BOOST_AUTO_TEST_CASE(CorrectJumpMnemonics)
            {
                auto code_module = make_unique<Encoder>();
                auto JGT = bitset<BITNESS>("001");
                auto JEQ = bitset<BITNESS>("010");
                auto JGE = bitset<BITNESS>("011");
                auto JLT = bitset<BITNESS>("100");
                auto JNE = bitset<BITNESS>("101");
                auto JLE = bitset<BITNESS>("110");
                auto JMP = bitset<BITNESS>("111");

                JGT |= 0b111 << 13;
                JEQ |= 0b111 << 13;
                JGE |= 0b111 << 13;
                JLT |= 0b111 << 13;
                JNE |= 0b111 << 13;
                JLE |= 0b111 << 13;
                JMP |= 0b111 << 13;

                BOOST_TEST(code_module->Encode(jump("JGT"))== JGT.to_string());
                BOOST_TEST(code_module->Encode(jump("JEQ"))== JEQ.to_string());
                BOOST_TEST(code_module->Encode(jump("JGE"))== JGE.to_string());
                BOOST_TEST(code_module->Encode(jump("JLT"))== JLT.to_string());
                BOOST_TEST(code_module->Encode(jump("JNE"))== JNE.to_string());
                BOOST_TEST(code_module->Encode(jump("JLE"))== JLE.to_string());
                BOOST_TEST(code_module->Encode(jump("JMP"))== JMP.to_string());
            }

            BOOST_AUTO_TEST_CASE(CorrectDestMnemonics)
            {
                const auto code_module = make_unique<Encoder>();
                auto b_M = bitset<BITNESS>("001") << DEST_SHIFT;
                auto b_D = bitset<BITNESS>("010") << DEST_SHIFT;
                auto b_MD = bitset<BITNESS>("011") << DEST_SHIFT;
                auto b_A = bitset<BITNESS>("100") << DEST_SHIFT;
                auto b_AM = bitset<BITNESS>("101") << DEST_SHIFT;
                auto b_AD = bitset<BITNESS>("110") << DEST_SHIFT;
                auto b_AMD = bitset<BITNESS>("111") << DEST_SHIFT;

                b_M |= 0b111 << 13;
                b_D |= 0b111 << 13;
                b_MD |= 0b111 << 13;
                b_A |= 0b111 << 13;
                b_AM |= 0b111 << 13;
                b_AD |= 0b111 << 13;
                b_AMD |= 0b111 << 13;

                BOOST_TEST(code_module->Encode(dest("M"))== b_M.to_string());
                BOOST_TEST(code_module->Encode(dest("D"))== b_D.to_string());
                BOOST_TEST(code_module->Encode(dest("MD")) == b_MD.to_string());
                BOOST_TEST(code_module->Encode(dest("A"))== b_A.to_string());
                BOOST_TEST(code_module->Encode(dest("AM")) == b_AM.to_string());
                BOOST_TEST(code_module->Encode(dest("AD")) == b_AD.to_string());
                BOOST_TEST(code_module->Encode(dest("AMD")) == b_AMD.to_string());
            }

            BOOST_AUTO_TEST_CASE(CorrectCompMnemonics)
            {
                const auto code_module = make_unique<Encoder>();
                const auto zero = bitset<BITNESS>("1110101010") << COMP_SHIFT;
                const auto one = bitset<BITNESS>("1110111111") << COMP_SHIFT;
                const auto nOne = bitset<BITNESS>("1110111010") << COMP_SHIFT;
                const auto D = bitset<BITNESS>("1110001100") << COMP_SHIFT;
                const auto A = bitset<BITNESS>("1110110000") << COMP_SHIFT;
                const auto nD = bitset<BITNESS>("1110001101") << COMP_SHIFT;
                const auto nA = bitset<BITNESS>("1110110001") << COMP_SHIFT;
                const auto negD = bitset<BITNESS>("1110001111") << COMP_SHIFT;
                const auto negA = bitset<BITNESS>("1110110011") << COMP_SHIFT;
                const auto Dp1 = bitset<BITNESS>("1110011111") << COMP_SHIFT;
                const auto Ap1 = bitset<BITNESS>("1110110111") << COMP_SHIFT;
                const auto Dm1 = bitset<BITNESS>("1110001110") << COMP_SHIFT;
                const auto Am1 = bitset<BITNESS>("1110110010") << COMP_SHIFT;
                const auto DpA = bitset<BITNESS>("1110000010") << COMP_SHIFT;
                const auto DmA = bitset<BITNESS>("1110010011") << COMP_SHIFT;
                const auto AmD = bitset<BITNESS>("1110000111") << COMP_SHIFT;
                const auto DandA = bitset<BITNESS>("1110000000") << COMP_SHIFT;
                const auto DorA = bitset<BITNESS>("1110010101") << COMP_SHIFT;

                const auto M = bitset<BITNESS>("1111110000") << COMP_SHIFT;
                const auto nM = bitset<BITNESS>("1111110001") << COMP_SHIFT;
                const auto negM = bitset<BITNESS>("1111110011") << COMP_SHIFT;
                const auto Mp1 = bitset<BITNESS>("1111110111") << COMP_SHIFT;
                const auto Mm1 = bitset<BITNESS>("1111110010") << COMP_SHIFT;
                const auto DpM = bitset<BITNESS>("1111000010") << COMP_SHIFT;
                const auto DmM = bitset<BITNESS>("1111010011") << COMP_SHIFT;
                const auto MmD = bitset<BITNESS>("1111000111") << COMP_SHIFT;
                const auto DandM = bitset<BITNESS>("1111000000") << COMP_SHIFT;
                const auto DorM = bitset<BITNESS>("1111010101") << COMP_SHIFT;

                BOOST_TEST(code_module->Encode(comp("0"))== zero.to_string());
                BOOST_TEST(code_module->Encode(comp("1"))== one.to_string());
                BOOST_TEST(code_module->Encode(comp("-1"))== nOne.to_string());
                BOOST_TEST(code_module->Encode(comp("D"))== D.to_string());
                BOOST_TEST(code_module->Encode(comp("A"))== A.to_string());
                BOOST_TEST(code_module->Encode(comp("!D"))== nD.to_string());
                BOOST_TEST(code_module->Encode(comp("!A"))== nA.to_string());
                BOOST_TEST(code_module->Encode(comp("-D"))== negD.to_string());
                BOOST_TEST(code_module->Encode(comp("-A"))== negA.to_string());
                BOOST_TEST(code_module->Encode(comp("D+1"))== Dp1.to_string());
                BOOST_TEST(code_module->Encode(comp("A+1"))== Ap1.to_string());
                BOOST_TEST(code_module->Encode(comp("D-1"))== Dm1.to_string());
                BOOST_TEST(code_module->Encode(comp("A-1"))== Am1.to_string());
                BOOST_TEST(code_module->Encode(comp("D+A"))== DpA.to_string());
                BOOST_TEST(code_module->Encode(comp("D-A"))== DmA.to_string());
                BOOST_TEST(code_module->Encode(comp("A-D"))== AmD.to_string());
                BOOST_TEST(code_module->Encode(comp("D&A"))== DandA.to_string());
                BOOST_TEST(code_module->Encode(comp("D|A"))== DorA.to_string());

                BOOST_TEST(code_module->Encode(comp("M"))== M.to_string());
                BOOST_TEST(code_module->Encode(comp("!M"))== nM.to_string());
                BOOST_TEST(code_module->Encode(comp("-M"))== negM.to_string());
                BOOST_TEST(code_module->Encode(comp("M+1"))== Mp1.to_string());
                BOOST_TEST(code_module->Encode(comp("M-1"))== Mm1.to_string());
                BOOST_TEST(code_module->Encode(comp("D+M"))== DpM.to_string());
                BOOST_TEST(code_module->Encode(comp("D-M"))== DmM.to_string());
                BOOST_TEST(code_module->Encode(comp("M-D"))== MmD.to_string());
                BOOST_TEST(code_module->Encode(comp("D&M"))== DandM.to_string());
                BOOST_TEST(code_module->Encode(comp("D|M"))== DorM.to_string());
            }

        BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE_END()
} // namespace tests
