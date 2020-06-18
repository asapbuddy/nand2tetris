#pragma once

#include "../API/SourceCodeFile.h"
#include <vector>

struct Assembler
{
    virtual ~Assembler() = default;

    /**
     * \brief compiles source code
     */
    virtual void Compile(SourceCodeFile sourceCodeFile) = 0;

    /**
     * \return Compiled source code in list of strings
     */
    virtual std::vector<std::string> GetCompilationResults() = 0;
};
