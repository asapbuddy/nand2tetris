#pragma once
#include <string>
#include <vector>


#include "../API/LookupTable.h"
#include "../Core/FabricModule.h"
#include "Commands/InstructionDecoder.h"


class Assembler
{
    const char* file_path_;
    std::vector<std::string> result_;
    LookupTable* lookup_table_;
    InstructionDecoder* instruction_decoder_;


public:
    Assembler(const char* path)
        : file_path_(path)
    {
        lookup_table_ = FabricModule::get_symbol_table();
        instruction_decoder_ = FabricModule::get_code_module();
    }

    ~Assembler()
    {
        delete lookup_table_;
        delete instruction_decoder_;
    }

    void process_labels() const;

    void compile();

    void save(const char* ext);
};
