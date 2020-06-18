#pragma once
#include "InstructionParts.h"

struct StatementParameters
{
    virtual ~StatementParameters() = default;

    virtual void IncreaseInstructionCounter() = 0;

    virtual std::string DecodeInstruction(const InstructionParts& packedInstruction) const = 0;

    virtual std::string DecodeAddress(const std::string& address) const = 0;

    virtual void AddLabel(const std::string& mnemonic) const = 0;
};
