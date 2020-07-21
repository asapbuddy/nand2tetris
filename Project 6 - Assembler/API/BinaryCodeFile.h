#pragma once
#include <iosfwd>
#include <string>
#include <vector>

#include "TextFile.h"

class BinaryCodeFile : public TextFile
{
    const char* filename_;
public:

    explicit BinaryCodeFile(const char* filename)
        : filename_(filename)
    {
    }

    BinaryCodeFile(const BinaryCodeFile& sourceCode)
        : BinaryCodeFile(sourceCode.filename_)
    {
    }

    std::ifstream GetFileInputStream() const override;

    std::ofstream GetFileOutputStream() const override;

    std::vector<std::string> ReadAllLines() override;

    void WriteAllLines(std::vector<std::string> lines) override;

    ~BinaryCodeFile() override = default;
};
