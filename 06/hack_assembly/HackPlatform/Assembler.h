#pragma once
#include <string>
#include <vector>


#include "FabricModule.h"
#include "../API/Assembler.h"
#include "Statements/ProcessingParameters.h"


class TwoPassAssembler : public Assembler
{
    const char* file_path_;
    std::vector<std::string> result_;
    unique_ptr<Fabric> fabric_;
    ProcessingParameters statement_parameters_;


public:
    explicit TwoPassAssembler(const char* path)
        : file_path_(path),
          fabric_(make_unique<FabricModule>()),
          statement_parameters_(fabric_->get_symbol_table(), fabric_->get_code_module())
    {
    }

    ~TwoPassAssembler() override = default;

    void process_labels();

    void Compile() override;

    void SaveBinary() override;
};
