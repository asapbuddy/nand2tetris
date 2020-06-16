#pragma once


#include "../API/LookupTable.h"
#include "../HACK/Decoder.h"
#include "../HACK/SymbolTable.h"

class FabricModule final
{
public:
    static InstructionDecoder* get_code_module()
    {
        return new Decoder;
    }

    static LookupTable* get_symbol_table()
    {
        return new SymbolTable;
    }
};
