#pragma once
#include <memory>


#include "Assembler.h"
#include "Context.h"


struct Factory
{
    virtual ~Factory() = default;

    /**
     * \brief create InstructionDecoder and LookupTable to init Parameters
     * \return parameters for command execution
     */
    virtual std::unique_ptr<Context> CreateContext() = 0;

    virtual std::unique_ptr<Assembler> CreateAssembler() = 0;
};
