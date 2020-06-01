#pragma once
#include <cstdint>

#include "../API/ICodeModule.h"
#include "../API/IParserModule.h"
#include "../API/ISymbolTable.h"
#include "../Modules/BaseCodeModule.h"
#include "../Modules/BaseParserModule.h"
#include "../Modules/BaseSymbolTable.h"

struct IModuleFabric
{
    virtual IParserModule* get_parser_module() = 0;
    virtual ISymbolTable* get_symbol_table() = 0;

    virtual ~IModuleFabric() = default;
};

template <uint8_t Bits>
struct DefaultFabricModule final : IModuleFabric
{
    IParserModule* get_parser_module() override
    {
        auto code_module = new BaseCodeModule<Bits>;
        return new BaseParserModule(code_module);
    }

    ISymbolTable* get_symbol_table() override
    {
        return new BaseSymbolTable;
    }
};

