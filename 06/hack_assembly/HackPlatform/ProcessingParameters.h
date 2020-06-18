#pragma once
#include <memory>

#include "../API/InstructionDecoder.h"
#include "../API/LookupTable.h"
#include "../API/StatementParameters.h"

class ProcessingParameters final : public StatementParameters
{
    std::unique_ptr<LookupTable> lookup_table_;
    std::unique_ptr<InstructionDecoder> instruction_decoder_;
    mutable unsigned variable_offset_ = 16, processed_instructions_ = 0;
public:
    ProcessingParameters(std::unique_ptr<LookupTable>&& lookupTable, std::unique_ptr<InstructionDecoder>&& instructionDecoder)
        : lookup_table_(std::move(lookupTable)), instruction_decoder_(std::move(instructionDecoder))
    {
    }

    void IncreaseInstructionCounter() override;

    void AddLabel(const std::string& mnemonic) const override;

    std::string DecodeInstruction(const InstructionParts& packedInstruction) const override;

    std::string DecodeAddress(const std::string& address) const override;

    ~ProcessingParameters() override = default;
};
