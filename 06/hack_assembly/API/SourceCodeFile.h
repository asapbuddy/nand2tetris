#pragma once
#include <fstream>
#include <iosfwd>

#include "TextFile.h"

class SourceCodeFile final : public TextFile
{
    const char* filename_;
    bool is_file_checked_ = false;

public:
    explicit SourceCodeFile(const char* filename)
        : filename_(filename)
    {
    }

    SourceCodeFile(const SourceCodeFile& sourceCode)
        : SourceCodeFile(sourceCode.filename_)
    {
        is_file_checked_ = sourceCode.is_file_checked_;
    }

    void CheckFile();

    std::ifstream GetFileInputStream() const override;

    std::ofstream GetFileOutputStream() const override;

    std::vector<std::string> ReadAllLines() override;

    void WriteAllLines(std::vector<std::string>) override;

    ~SourceCodeFile() override = default;
};
