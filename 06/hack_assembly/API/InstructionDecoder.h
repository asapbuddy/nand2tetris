#pragma once
#include "InstructionParts.h"

/**
 * \brief Translate Hack assembly to binary code.
 * \return aligned bit-values
 */
struct InstructionDecoder
{
    virtual ~InstructionDecoder() = default;

    /**
     * \brief clients does not actually know about processing
     * \return full instruction bits
     */
    virtual std::string decode(const InstructionParts& instruction) = 0;
};
