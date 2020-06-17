#pragma once
#include "PackedInstruction.h"

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
    virtual std::string decode(const PackedInstruction& instruction) = 0;
};
