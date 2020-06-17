#pragma once
#include <string>
#include <vector>


#include "../Core/FabricModule.h"
#include "Statements/StatementParameters.h"


class Assembler
{
    const char* file_path_;
    std::vector<std::string> result_;
    StatementParameters statement_parameters_;


public:
    explicit Assembler(const char* path)
        : file_path_(path),
          statement_parameters_(
              FabricModule::get_symbol_table(),
              FabricModule::get_code_module()
          )
    {
    }

    ~Assembler() = default;

    void process_labels();

    void assemble();

    void save(const char* ext);
};
