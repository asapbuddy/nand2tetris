#pragma once
#include <cstdint>

#include "../API/ICodeModule.h"
#include "../API/IParserModule.h"
#include "../API/ISymbolTable.h"
#include "../Modules/BaseCodeModule.h"
#include "../Modules/BaseParserModule.h"
#include "../Modules/BaseSymbolTable.h"

template <uint8_t Bits>
struct DefaultModuleFabric
{
    ICodeModule* get_code_module() const;
    IParserModule* get_parser_module();
    ISymbolTable* get_symbol_table();
};

template <uint8_t Bits>
ICodeModule* DefaultModuleFabric<Bits>::get_code_module() const
{
    auto code_module = new BaseCodeModule<Bits>;
    return code_module;
}

template <uint8_t Bits>
IParserModule* DefaultModuleFabric<Bits>::get_parser_module()
{
    return new BaseParserModule;
}

template <uint8_t Bits>
ISymbolTable* DefaultModuleFabric<Bits>::get_symbol_table()
{
    return new BaseSymbolTable;
}
