#pragma once
#include <memory>

#include "StatementParameters.h"


struct Fabric
{
    virtual ~Fabric() = default;

    /**
     * \brief create InstructionDecoder and LookupTable to init Parameters
     * \return parameters for command execution
     */
    virtual std::unique_ptr<StatementParameters> CreateParameters() = 0;
};
