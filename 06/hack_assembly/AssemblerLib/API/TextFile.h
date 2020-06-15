#pragma once

#include <iosfwd>

struct TextFile
{
    virtual ~TextFile() = default;

    virtual std::ifstream GetFileStream() = 0;
};
