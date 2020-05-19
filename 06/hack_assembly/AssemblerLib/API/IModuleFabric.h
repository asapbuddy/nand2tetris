#pragma once
#include "ICodeModule.h"
#include "IParserModule.h"
#include "ISymbolTable.h"

struct IModuleFabric
{
    virtual ~IModuleFabric() = default;
    virtual ICodeModule* get_code_module() = 0;
    virtual IParserModule* get_parser_module() = 0;
    virtual ISymbolTable* get_symbol_table() = 0;
};
