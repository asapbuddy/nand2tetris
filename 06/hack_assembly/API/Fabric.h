#pragma once
#include <memory>

#include "LookupTable.h"
#include "../HackPlatform/Statements/InstructionDecoder.h"

struct Fabric
{
    virtual ~Fabric() = default;

    /** 
     * \return module for decoding mnemonic to binary 
     */
    virtual std::unique_ptr<InstructionDecoder> get_code_module() = 0;

    /**
     * \brief need for place right binary data into assembled file
     * \return table for producing binary code 
     */
    virtual std::unique_ptr<LookupTable> get_symbol_table() = 0;
};
