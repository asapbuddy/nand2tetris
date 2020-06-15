#pragma once

#include "../API/InstructionHandler.h"
#include "../API/LookupTable.h"
#include "../HACK/CodeGenerator.h"
#include "../HACK/Parser.h"
#include "../HACK/SymbolTable.h"

class FabricModule final
{
    FabricModule(const FabricModule& other) = delete;
    FabricModule(FabricModule&& other) noexcept = delete;
    FabricModule& operator=(const FabricModule& other) = delete;
    FabricModule& operator=(FabricModule&& other) noexcept = delete;

    FabricModule() = default;

    InstructionHandler* code_module_ = nullptr;
    LookupTable* symbol_table_ = nullptr;
    AssemblerParser* parser_module_ = nullptr;

public:

    static FabricModule& instance()
    {
        static FabricModule instance;
        return instance;
    }

    InstructionHandler* get_code_module()
    {
        if(code_module_ == nullptr)
            code_module_ = new CodeGenerator;

        return code_module_;
    }

    AssemblerParser* get_parser_module()
    {
        if(parser_module_ == nullptr)
            parser_module_ = new Parser;
        return parser_module_;
    }


    LookupTable* get_symbol_table()
    {
        if(symbol_table_ == nullptr)
            symbol_table_ = new SymbolTable;

        return symbol_table_;
    }

    ~FabricModule()
    {
        if(code_module_ != nullptr)
            delete code_module_;
        if(parser_module_ != nullptr)
            delete parser_module_;
        if(symbol_table_ != nullptr)
            delete symbol_table_;
    }
};
