#pragma once
#include "../API/IModuleFabric.h"

class DefaultModuleFabric : public IModuleFabric
{
public:
    ICodeModule* get_code_module() override;
    IParserModule* get_parser_module() override;
    ISymbolTable* get_symbol_table() override;
};
