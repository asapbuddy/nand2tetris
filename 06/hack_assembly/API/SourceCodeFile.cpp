#include "SourceCodeFile.h"

#include <filesystem>
#include <iosfwd>
#include <iterator>
#include <string>
#include <vector>

void SourceCodeFile::CheckFile()
{
    const std::filesystem::path input(filename_);
    if(!exists(input))
        throw "Input file doesn't exist";

    if(!input.has_extension() || input.extension() != ".asm")
        throw "Input file has unknown extension.\n Please use *.asm.";

    if(is_empty(input))
        throw "Input file is empty";

    is_file_checked_ = true;
}

std::ifstream SourceCodeFile::GetFileInputStream() const
{
    if(!is_file_checked_)
        throw "Check source file first";
    return std::ifstream(filename_);
}

std::ofstream SourceCodeFile::GetFileOutputStream() const
{
    throw "Could not write to source code file";
}

std::vector<std::string> SourceCodeFile::ReadAllLines()
{
    auto reader(GetFileInputStream());
    std::vector<std::string> result;
    std::copy(std::istream_iterator<std::string>(reader),
              std::istream_iterator<std::string>(),
              std::back_inserter(result));
    return result;
}

void SourceCodeFile::WriteAllLines(std::vector<std::string>)
{
    GetFileOutputStream();
}
