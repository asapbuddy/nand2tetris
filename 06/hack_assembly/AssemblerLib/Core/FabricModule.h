#pragma once


#include "../API/LookupTable.h"
#include "../HACK/Decoder.h"
#include "../HACK/SymbolTable.h"

class FabricModule final
{
    FabricModule(const FabricModule& other) = delete;
    FabricModule(FabricModule&& other) noexcept = delete;
    FabricModule& operator=(const FabricModule& other) = delete;
    FabricModule& operator=(FabricModule&& other) noexcept = delete;

    FabricModule() = default;

    InstructionDecoder* code_module_ = nullptr;
    LookupTable* symbol_table_ = nullptr;

public:

    static FabricModule& instance()
    {
        static FabricModule instance;
        return instance;
    }

    InstructionDecoder* get_code_module()
    {
        if(code_module_ == nullptr)
            code_module_ = new Decoder;

        return code_module_;
    }

    static LookupTable& get_symbol_table()
    {
        static SymbolTable table;
        return table;
    }

    ~FabricModule()
    {
        if(code_module_ != nullptr)
            delete code_module_;
        if(symbol_table_ != nullptr)
            delete symbol_table_;
    }
};
