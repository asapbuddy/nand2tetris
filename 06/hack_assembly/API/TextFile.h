#pragma once

#include <iosfwd>

struct TextFile
{
    virtual ~TextFile() = default;

    //TODO create universal stream for read/write or add new method
    virtual std::ifstream GetFileStream() = 0;
};
