#include <boost/test/unit_test.hpp>

#include "Fixtures.h"
#include <bitset>
#include "AssemblerLib/HACK/Assembler.h"
using namespace std;


namespace assembler_tests
{
    BOOST_FIXTURE_TEST_SUITE(ModulesTests, Configuration)

        BOOST_AUTO_TEST_SUITE(BaseCodeModuleTest)

            BOOST_AUTO_TEST_CASE(AddTest)
            {
                const std::string name("Add");
                create_assembly(name);
                const std::string actual_file = locate_test_file(name.c_str(), ".hack");
                const std::string expected_file = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actual_file, expected_file) == true);
            }


            BOOST_AUTO_TEST_CASE(MaxTest)
            {
                const std::string name("Max");
                create_assembly(name);
                const std::string actual_file = locate_test_file(name.c_str(), ".hack");
                const std::string expected_file = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actual_file, expected_file) == true);
            }


            BOOST_AUTO_TEST_CASE(RectTest)
            {
                const std::string name("Rect");
                create_assembly(name);
                const std::string actual_file = locate_test_file(name.c_str(), ".hack");
                const std::string expected_file = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actual_file, expected_file) == true);
            }

            BOOST_AUTO_TEST_CASE(RectLTest)
            {
                const std::string name("RectL");
                create_assembly(name);
                const std::string actual_file = locate_test_file(name.c_str(), ".hack");
                const std::string expected_file = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actual_file, expected_file) == true);
            }

            BOOST_AUTO_TEST_CASE(MaxLTest)
            {
                const std::string name("MaxL");
                create_assembly(name);
                const std::string actual_file = locate_test_file(name.c_str(), ".hack");
                const std::string expected_file = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actual_file, expected_file) == true);
            }


        BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE_END()
} // namespace tests
