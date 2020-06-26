#pragma once
#include <memory>
#include <string>
#include <vector>

#include "../API/Assembler.h"
#include "../API/SourceCodeFile.h"
#include "../API/Context.h"


class TwoPassAssembler final : public Assembler
{
    std::vector<std::string> result_;
    std::unique_ptr<Context> context_;

public:
    explicit TwoPassAssembler(std::unique_ptr<Context>&& context)
        : context_(std::move(context))
    {
    }

    ~TwoPassAssembler() override = default;

    void Compile(SourceCodeFile sourceCodeFile) override;

    std::vector<std::string> GetCompilationResults() override;

private:
    void ProcessLabels(const SourceCodeFile& sourceCode) const;

    void ProcessInstructions(const SourceCodeFile& sourceFile);
};
