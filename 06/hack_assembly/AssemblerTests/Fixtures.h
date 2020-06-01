#pragma once


#include <AssemblerLib/Core/DefaultModuleFabric.h>
#include <AssemblerLib/Modules/BaseAssemblerModule.h>


#include "../AssemblerLib/Modules/BaseCodeModule.h"
#include "../AssemblerLib/Modules/BaseParserModule.h"


namespace assembler_tests
{
    constexpr uint8_t bitness = 16;

    struct Configuration
    {
        IModuleFabric* fabric = new DefaultFabricModule<16>;
        string tests_path{"..\\AssemblerTests\\Tests\\"};

        string get_test_path(const char* name) const
        {
            string result(tests_path);
            result.append(name);
            result.append(".asm");
            return result;
        }

        void create_assembly(const string& name)
        {
            string path(tests_path);
            path.append(name).append(".asm");
            BaseAssemblerModule<bitness> assembler_module(path.c_str(), fabric);
            BOOST_ASSERT(assembler_module.init() == true);
            assembler_module.process_labels();
            assembler_module.compile();
            assembler_module.save("hack");
        }

        ~Configuration() { delete fabric; }
    };
} // namespace tests
