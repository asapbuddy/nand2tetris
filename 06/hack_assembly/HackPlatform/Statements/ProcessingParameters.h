#pragma once
#include <memory>

#include "InstructionDecoder.h"
#include "../../API/LookupTable.h"
#include "../../API/StatementParameters.h"

class ProcessingParameters : public StatementParameters
{
    std::unique_ptr<LookupTable> lookup_table_;
    std::unique_ptr<InstructionDecoder> instruction_decoder_;
    unsigned AddressInstructionOffset = 16, ProcessedInstructions = 0;
public:
    ProcessingParameters(std::unique_ptr<LookupTable>&& lookup_table, std::unique_ptr<InstructionDecoder>&& instruction_decoder)
        : lookup_table_(std::move(lookup_table)), instruction_decoder_(std::move(instruction_decoder))
    {
    }

    unsigned GetNextAddressOffset() override
    {
        return AddressInstructionOffset++;
    }

    void IncreaseInstructionCounter() override
    {
        ++ProcessedInstructions;
    }

    unsigned GetInstructionCounter() const override
    {
        return ProcessedInstructions;
    }

    //TODO Need to Fix that
    LookupTable* GetLookupTable() const
    {
        return lookup_table_.get();
    }

    InstructionDecoder* GetInstructionDecoder() const
    {
        return instruction_decoder_.get();
    }

    ~ProcessingParameters() override = default;
};
