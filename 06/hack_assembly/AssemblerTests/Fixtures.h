#pragma once


#include <AssemblerLib/Core/DefaultModuleFabric.h>

#include "../AssemblerLib/Modules/BaseCodeModule.h"
#include "../AssemblerLib/Modules/BaseParserModule.h"


namespace assembler_tests
{
    struct Configuration
    {
        DefaultModuleFabric<16> fabric;
        ICodeModule* code_module = fabric.get_code_module();
        IParserModule* parser_module = fabric.get_parser_module();
    };
} // namespace tests
