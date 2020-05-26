﻿#include <boost/test/unit_test.hpp>

#include "Fixtures.h"
#include <bitset>
using namespace std;

namespace assembler_tests
{
    BOOST_FIXTURE_TEST_SUITE(ModulesTests, Configuration)

        BOOST_AUTO_TEST_SUITE(BaseParserModule)

            BOOST_AUTO_TEST_CASE(CorrectBitsOperation)
            {
                BOOST_TEST(parser_module.comp() == 0b0001000000000000);
            }

        BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE_END()
} // namespace tests
