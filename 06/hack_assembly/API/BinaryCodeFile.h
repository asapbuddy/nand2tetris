#pragma once
#include <iosfwd>
#include <string>
#include <vector>

#include "TextFile.h"

class BinaryCodeFile : public TextFile
{
public:
    std::ifstream GetFileInputStream() override;
    std::ofstream GetFileOutputStream() override;
    std::vector<std::string> ReadAllLines() override;
    void WriteAllLines(std::vector<std::string>) override;
};
