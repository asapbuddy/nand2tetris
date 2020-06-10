#pragma once
#include <cstdint>

#include "../Modules/CodeModule.h"
#include "../Modules/SymbolTable.h"
#include "../Modules/ParserModule.h"


template <uint8_t Bits>
class FabricModule final
{
public:
    FabricModule(const FabricModule& other) = delete;
    FabricModule(FabricModule&& other) noexcept = delete;
    FabricModule& operator=(const FabricModule& other) = delete;
    FabricModule& operator=(FabricModule&& other) noexcept = delete;
private:
    FabricModule()
    {
    }

    ICodeModule* code_module_ = nullptr;
    ISymbolTable* symbol_table_ = nullptr;
    IParserModule* parser_module_ = nullptr;
public:

    static FabricModule& get_instance()
    {
        static FabricModule instance;
        return instance;
    }

    ICodeModule* get_code_module()
    {
        if(code_module_ == nullptr)
            code_module_ = new CodeModule<Bits>;

        return code_module_;
    }

    IParserModule* get_parser_module()
    {
        if(parser_module_ == nullptr)
            parser_module_ = new ParserModule();

        return parser_module_;
    }


    ISymbolTable* get_symbol_table()
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
