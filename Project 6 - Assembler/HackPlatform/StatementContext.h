#pragma once
#include <memory>

#include "../API/InstructionEncoder.h"
#include "../API/LookupTable.h"
#include "../API/Context.h"

class StatementContext final : public Context
{
    std::unique_ptr<LookupTable> lookup_table_;
    std::unique_ptr<InstructionEncoder> instruction_decoder_;
    mutable unsigned variable_offset_ = 16, processed_instructions_ = 0;
public:
    StatementContext(std::unique_ptr<LookupTable>&& lookupTable, std::unique_ptr<InstructionEncoder>&& instructionDecoder)
        : lookup_table_(std::move(lookupTable)), instruction_decoder_(std::move(instructionDecoder))
    {
    }

    void IncreaseInstructionCounter() override;

    void AddLabel(const std::string& mnemonic) const override;

    std::string DecodeInstruction(const InstructionParts& packedInstruction) const override;

    std::string DecodeAddress(const std::string& address) const override;

    ~StatementContext() override = default;
};
