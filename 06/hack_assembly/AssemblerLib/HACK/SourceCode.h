#pragma once
#include <fstream>
#include <iosfwd>

#include "../API/TextFile.h"

class SourceCode : public TextFile
{
    const char* filename_;
    void CheckFile() const;

public:
    SourceCode(const char* filename)
        : filename_(filename)
    {
    }

    SourceCode(const SourceCode& source_code)
        : SourceCode(source_code.filename_)
    {
    }

    std::ifstream GetFileStream() override;
};
