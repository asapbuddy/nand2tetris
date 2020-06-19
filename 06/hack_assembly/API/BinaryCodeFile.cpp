#include <fstream>
#include <iosfwd>
#include <iterator>

#include "BinaryCodeFile.h"

std::ifstream BinaryCodeFile::GetFileInputStream() const
{
    return std::ifstream(filename_);
}

std::ofstream BinaryCodeFile::GetFileOutputStream() const
{
    return std::ofstream(filename_);
}

std::vector<std::string> BinaryCodeFile::ReadAllLines()
{
    auto reader(GetFileInputStream());
    std::vector<std::string> result;
    std::copy(std::istream_iterator<std::string>(reader),
              std::istream_iterator<std::string>(),
              std::back_inserter(result));
    return result;
}

void BinaryCodeFile::WriteAllLines(std::vector<std::string> lines)
{
    const std::string fn(filename_);
    const auto dot = fn.rfind('.', fn.length());
    const auto outputFn = dot == std::string::npos ? fn + "hack" : fn.substr(0, dot + 1) + "hack";
    std::ofstream outputFile(outputFn);
    const std::ostream_iterator<std::string> outputIterator(outputFile, "\n");
    std::copy(lines.begin(), lines.end(), outputIterator);
    outputFile.close();
}
