#pragma once
#include <filesystem>
#include <fstream>

#include "../errors/HelperError.h"

using namespace std;

class helper
{
public:
    static ifstream process_source(filesystem::path input)
    {
        if(!exists(input))
            throw helper_error("Input file doesn't exist");

        if(!input.has_extension() || input.extension() != ".asm")
            throw helper_error("Input file has unknown extension.\n Please use *.asm.");

        if(!filesystem::is_empty(input))
            throw helper_error("Input file is empty");

        return ifstream(input.c_str());
    }
};
