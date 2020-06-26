#include "StatementContext.h"

#include <bitset>


void StatementContext::IncreaseInstructionCounter()
{
    ++processed_instructions_;
}

std::string StatementContext::DecodeInstruction(const InstructionParts& packedInstruction) const
{
    return instruction_decoder_->Encode(packedInstruction);
}

std::string StatementContext::DecodeAddress(const std::string& address) const
{
    if(!lookup_table_->Contains(address))
    {
        lookup_table_->AddEntry(address, variable_offset_++);
    }

    return std::bitset<16>(lookup_table_->GetAddress(address)).to_string();
}

void StatementContext::AddLabel(const std::string& mnemonic) const
{
    lookup_table_->AddEntry(mnemonic, processed_instructions_);
}
