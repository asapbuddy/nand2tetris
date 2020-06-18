#include "SourceCodeFile.h"

#include <filesystem>

void SourceCodeFile::CheckFile() const
{
    const std::filesystem::path input(filename_);
    if(!exists(input))
        throw "Input file doesn't exist";

    if(!input.has_extension() || input.extension() != ".asm")
        throw "Input file has unknown extension.\n Please use *.asm.";

    if(is_empty(input))
        throw "Input file is empty";
}

std::ifstream SourceCodeFile::GetFileInputStream()
{
    CheckFile();
    return std::ifstream(filename_);
}

std::ofstream SourceCodeFile::GetFileOutputStream()
{
    throw "Could not write to source code file";
}

std::vector<std::string> SourceCodeFile::ReadAllLines()
{
}

void SourceCodeFile::WriteAllLines(std::vector<std::string>)
{
}
