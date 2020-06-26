#pragma once
#include "InstructionParts.h"

struct Context
{
    virtual ~Context() = default;

    virtual void IncreaseInstructionCounter() = 0;

    virtual std::string DecodeInstruction(const InstructionParts& packedInstruction) const = 0;

    virtual std::string DecodeAddress(const std::string& address) const = 0;

    virtual void AddLabel(const std::string& mnemonic) const = 0;
};
