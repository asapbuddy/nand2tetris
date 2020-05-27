#pragma once

#include "../AssemblerLib/Modules/BaseCodeModule.h"
#include "../AssemblerLib/Modules/BaseParserModule.h"


namespace assembler_tests
{
    struct Configuration
    {
        BaseCodeModule<16> code_module;
        BaseParserModule parser_module;
    };
} // namespace tests
