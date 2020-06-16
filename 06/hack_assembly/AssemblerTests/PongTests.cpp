#include <boost/test/unit_test.hpp>

#include "Fixtures.h"
#include <bitset>
#include "AssemblerLib/HACK/Assembler.h"
using namespace std;


namespace assembler_tests
{
    BOOST_FIXTURE_TEST_SUITE(PongTests, Configuration)

        BOOST_AUTO_TEST_SUITE(PongTest)

            BOOST_AUTO_TEST_CASE(PongTest)
            {
                const std::string name("Pong");
                create_assembly(name);
                const std::string actual_file = locate_test_file(name.c_str(), ".hack");
                const std::string expected_file = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actual_file, expected_file) == true);
            }

            BOOST_AUTO_TEST_CASE(PongLTest)
            {
                const std::string name("PongL");
                create_assembly(name);
                const std::string actual_file = locate_test_file(name.c_str(), ".hack");
                const std::string expected_file = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actual_file, expected_file) == true);
            }

        BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE_END()
} // namespace tests
