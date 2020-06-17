#pragma once
#include "LookupTable.h"
#include "../HackPlatform/Statements/InstructionDecoder.h"

struct StatementParameters
{
    virtual ~StatementParameters() = default;

    virtual unsigned GetNextAddressOffset() = 0;

    virtual void IncreaseInstructionCounter() = 0;

    virtual unsigned GetInstructionCounter() const = 0;

    //TODO move lookup and decoding logic here
    //TODO deprecate returning raw pointers to clients

    virtual LookupTable* GetLookupTable() const = 0;

    virtual InstructionDecoder* GetInstructionDecoder() const = 0;
};
