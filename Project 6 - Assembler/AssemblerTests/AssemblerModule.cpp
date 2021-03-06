﻿// ReSharper disable CppInconsistentNaming
#include <boost/test/unit_test.hpp>

#include "Fixtures.h"
#include <bitset>
using namespace std;


namespace assembler_tests
{
    BOOST_FIXTURE_TEST_SUITE(ModulesTests, Configuration)

        BOOST_AUTO_TEST_SUITE(BaseCodeModuleTest)

            BOOST_AUTO_TEST_CASE(AddTest)
            {
                const std::string name("Add");
                create_assembly(name);
                const auto actualFile = locate_test_file(name.c_str(), ".hack");
                const auto expectedFile = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actualFile, expectedFile) == true);
            }


            BOOST_AUTO_TEST_CASE(MaxTest)
            {
                const std::string name("Max");
                create_assembly(name);
                const auto actualFile = locate_test_file(name.c_str(), ".hack");
                const auto expectedFile = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actualFile, expectedFile) == true);
            }


            BOOST_AUTO_TEST_CASE(RectTest)
            {
                const std::string name("Rect");
                create_assembly(name);
                const auto actualFile = locate_test_file(name.c_str(), ".hack");
                const auto expectedFile = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actualFile, expectedFile) == true);
            }

            BOOST_AUTO_TEST_CASE(RectLTest)
            {
                const std::string name("RectL");
                create_assembly(name);
                const auto actualFile = locate_test_file(name.c_str(), ".hack");
                const auto expectedFile = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actualFile, expectedFile) == true);
            }

            BOOST_AUTO_TEST_CASE(MaxLTest)
            {
                const std::string name("MaxL");
                create_assembly(name);
                const auto actualFile = locate_test_file(name.c_str(), ".hack");
                const auto expectedFile = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actualFile, expectedFile) == true);
            }

            BOOST_AUTO_TEST_CASE(PongTest)
            {
                const std::string name("Pong");
                create_assembly(name);
                const auto actualFile = locate_test_file(name.c_str(), ".hack");
                const auto expectedFile = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actualFile, expectedFile) == true);
            }

            BOOST_AUTO_TEST_CASE(PongLTest)
            {
                const std::string name("PongL");
                create_assembly(name);
                const auto actualFile = locate_test_file(name.c_str(), ".hack");
                const auto expectedFile = locate_test_file(name.c_str(), "_expected.hack");

                BOOST_TEST(compare_two_files(actualFile, expectedFile) == true);
            }


        BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE_END()
} // namespace tests
