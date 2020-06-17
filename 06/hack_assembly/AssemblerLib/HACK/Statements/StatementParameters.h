#pragma once
#include "InstructionDecoder.h"
#include "../../API/LookupTable.h"

class StatementParameters
{
    LookupTable* const lookup_table_;
    InstructionDecoder* const instruction_decoder_;
    unsigned AddressInstructionOffset = 16, ProcessedInstructions = 0;
public:
    StatementParameters(LookupTable* const lookup_table, InstructionDecoder* const instruction_decoder)
        : lookup_table_(lookup_table), instruction_decoder_(instruction_decoder)
    {
    }

    unsigned GetNextAddressOffset()
    {
        return AddressInstructionOffset++;
    }

    void IncreaseInstructionCounter()
    {
        ++ProcessedInstructions;
    }

    unsigned GetInstructionCounter() const
    {
        return ProcessedInstructions;
    }

    LookupTable* GetLookupTable() const
    {
        return lookup_table_;
    }

    InstructionDecoder* GetInstructionDecoder() const
    {
        return instruction_decoder_;
    }

    ~StatementParameters()
    {
        delete lookup_table_;
        delete instruction_decoder_;
    }
};
