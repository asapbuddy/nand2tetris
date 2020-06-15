#pragma once
#include <bitset>

#include "../../API/InstructionStatement.h"
#include "../../API/LookupTable.h"
#include "../../Core/DefaultModuleFabric.h"
#include "../../Core/Helper.h"

class Address : public InstructionStatement
{
    string mnemonic_;

    inline static unsigned a_counter_ = 16;
    LookupTable* symbol_table_ = nullptr;

public:
    ~Address() override = default;

    Address(string&& mnemonic)
        : mnemonic_(std::move(mnemonic))
    {
        auto& fabric = FabricModule::instance();
        symbol_table_ = fabric.get_symbol_table();
    }

    string Decode() override
    {
        if(Helper::is_digit(mnemonic_))
            return std::bitset<16>(stoi(mnemonic_)).to_string();

        if(!symbol_table_->Contains(mnemonic_))
            symbol_table_->AddEntry(mnemonic_, a_counter_++);

        return std::bitset<16>(symbol_table_->GetAddress(mnemonic_)).to_string();
    }
};
