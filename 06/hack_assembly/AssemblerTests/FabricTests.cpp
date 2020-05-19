#include "../AssemblerLib/Core/DefaultModuleFabric.h"
#include "gtest/gtest.h"

TEST(Fabric, CanCreate)
{
    IModuleFabric* fabric = new DefaultModuleFabric;

    ICodeModule* code_module = fabric->get_code_module();
    IParserModule* parser_module = fabric->get_parser_module();
    ISymbolTable* system_table = fabric->get_symbol_table();

    ASSERT_NE(code_module, nullptr);
}
