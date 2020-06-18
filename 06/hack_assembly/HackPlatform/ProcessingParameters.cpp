#include "ProcessingParameters.h"

#include <bitset>


void ProcessingParameters::IncreaseInstructionCounter()
{
    ++processed_instructions_;
}

std::string ProcessingParameters::DecodeInstruction(const InstructionParts& packedInstruction) const
{
    return instruction_decoder_->decode(packedInstruction);
}

std::string ProcessingParameters::DecodeAddress(const std::string& address) const
{
    if(!lookup_table_->Contains(address))
    {
        lookup_table_->AddEntry(address, variable_offset_++);
    }

    return std::bitset<16>(lookup_table_->GetAddress(address)).to_string();
}

void ProcessingParameters::AddLabel(const std::string& mnemonic) const
{
    lookup_table_->AddEntry(mnemonic, processed_instructions_);
}
