#pragma once

#include <iosfwd>
#include <vector>

struct TextFile
{
    virtual ~TextFile() = default;

    virtual std::ifstream GetFileInputStream() = 0;
    virtual std::ofstream GetFileOutputStream() = 0;
    virtual std::vector<std::string> ReadAllLines() = 0;
    virtual void WriteAllLines(std::vector<std::string>) = 0;
};
