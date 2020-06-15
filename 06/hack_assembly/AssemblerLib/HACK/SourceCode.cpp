#include "SourceCode.h"

#include <filesystem>

void SourceCode::CheckFile() const
{
    const std::filesystem::path input(filename_);
    if(!exists(input))
        throw ("Input file doesn't exist");

    if(!input.has_extension() || input.extension() != ".asm")
        throw ("Input file has unknown extension.\n Please use *.asm.");

    if(is_empty(input))
        throw ("Input file is empty");
}

std::ifstream SourceCode::GetFileStream()
{
    CheckFile();
    return std::ifstream(filename_);
}
