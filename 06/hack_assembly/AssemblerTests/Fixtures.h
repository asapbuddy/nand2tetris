#pragma once

#include "../AssemblerLib/Modules/BaseCodeModule.h"
#include "../AssemblerLib/Modules/BaseParserModule.h"


namespace assembler_tests
{
    struct Configuration
    {
        BaseCodeModule code_module;
        BaseParserModule parser_module;
    };
} // namespace tests
