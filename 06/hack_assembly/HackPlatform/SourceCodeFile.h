#pragma once
#include <fstream>
#include <iosfwd>

#include "../API/TextFile.h"


class SourceCodeFile final : public TextFile
{
    const char* filename_;
    void CheckFile() const;

public:
    explicit SourceCodeFile(const char* filename)
        : filename_(filename)
    {
    }

    SourceCodeFile(const SourceCodeFile& source_code)
        : SourceCodeFile(source_code.filename_)
    {
    }

    std::ifstream GetFileStream() override;
};
