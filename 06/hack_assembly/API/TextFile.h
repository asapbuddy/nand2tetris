#pragma once

#include <iosfwd>
#include <vector>

struct TextFile
{
    virtual ~TextFile() = default;

    virtual std::ifstream GetFileInputStream() const = 0;
    virtual std::ofstream GetFileOutputStream() const = 0;
    virtual std::vector<std::string> ReadAllLines() = 0;
    virtual void WriteAllLines(std::vector<std::string> stringData) = 0;
};
