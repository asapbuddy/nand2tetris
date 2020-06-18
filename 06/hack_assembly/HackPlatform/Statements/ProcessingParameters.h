#pragma once
#include <memory>

#include "InstructionDecoder.h"
#include "../../API/LookupTable.h"
#include "../../API/StatementParameters.h"

class ProcessingParameters : public StatementParameters
{
    std::unique_ptr<LookupTable> lookup_table_;
    std::unique_ptr<InstructionDecoder> instruction_decoder_;
    mutable unsigned variable_offset_ = 16, processed_instructions_ = 0;
public:
    ProcessingParameters(std::unique_ptr<LookupTable>&& lookup_table, std::unique_ptr<InstructionDecoder>&& instruction_decoder)
        : lookup_table_(std::move(lookup_table)), instruction_decoder_(std::move(instruction_decoder))
    {
    }

    void IncreaseInstructionCounter() override;

    std::string DecodeInstruction(const InstructionParts& packed_instruction) const override;

    std::string DecodeAddress(const std::string& address) const override;

    void AddLabel(const std::string& mnemonic) const override;

    ~ProcessingParameters() override = default;
};
