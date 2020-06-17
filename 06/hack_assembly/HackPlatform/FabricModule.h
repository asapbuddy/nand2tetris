#pragma once


#include "Decoder.h"
#include "SymbolTable.h"
#include "../API/Fabric.h"
#include "../API/LookupTable.h"
#include "Statements/InstructionDecoder.h"

class FabricModule final : public Fabric
{
public:
    unique_ptr<InstructionDecoder> get_code_module() override
    {
        return make_unique<Decoder>();
    }

    unique_ptr<LookupTable> get_symbol_table() override
    {
        return make_unique<SymbolTable>();
    }

    ~FabricModule() override = default;
};
