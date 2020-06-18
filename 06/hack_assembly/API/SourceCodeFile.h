#pragma once
#include <fstream>
#include <iosfwd>

#include "TextFile.h"

class SourceCodeFile final : public TextFile
{
    const char* filename_;
    void CheckFile() const;

public:
    explicit SourceCodeFile(const char* filename)
        : filename_(filename)
    {
    }

    SourceCodeFile(const SourceCodeFile& sourceCode)
        : SourceCodeFile(sourceCode.filename_)
    {
    }

    std::ifstream GetFileInputStream() override;


    std::ofstream GetFileOutputStream() override;


    std::vector<std::string> ReadAllLines() override;
    
    void WriteAllLines(std::vector<std::string>) override;
    ~SourceCodeFile() override = default;
};
