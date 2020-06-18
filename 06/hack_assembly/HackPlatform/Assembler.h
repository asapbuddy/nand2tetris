#pragma once
#include <memory>
#include <string>
#include <vector>

#include "../API/Assembler.h"
#include "../API/SourceCodeFile.h"
#include "../API/StatementParameters.h"


class TwoPassAssembler final : public Assembler
{
    std::vector<std::string> result_;
    std::unique_ptr<StatementParameters> parameters_;

public:
    explicit TwoPassAssembler(std::unique_ptr<StatementParameters>&& parameters)
        : parameters_(std::move(parameters))
    {
    }

    ~TwoPassAssembler() override = default;

    void Compile(SourceCodeFile sourceCodeFile) override;

    std::vector<std::string> GetCompilationResults() override;

private:
    void ProcessLabels(SourceCodeFile sourceCode) const;

    void ProcessInstructions(SourceCodeFile sourceFile);
};
