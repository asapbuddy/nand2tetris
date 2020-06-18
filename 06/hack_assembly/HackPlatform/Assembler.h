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
    std::unique_ptr<Fabric> fabric_;
    std::unique_ptr<StatementParameters> statement_parameters_;


public:
    explicit TwoPassAssembler(const char* path)
        : file_path_(path),
          fabric_(std::make_unique<FabricModule>()),
          statement_parameters_(fabric_->CreateParameters())
    {
    }

    ~TwoPassAssembler() override = default;

    void process_labels() const;

    void Compile() override;

    void SaveBinary() override;
};
