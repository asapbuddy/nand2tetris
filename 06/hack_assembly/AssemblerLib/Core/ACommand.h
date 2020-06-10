#pragma once
#include "DefaultModuleFabric.h"
#include "Helper.h"
#include "../API/ICommand.h"
#include "../API/ISymbolTable.h"


class ACommand : public ICommand
{
    string mnemonic_;

    inline static unsigned a_counter_ = 16;
    ISymbolTable* symbol_table_ = nullptr;

public:
    ~ACommand() override = default;

    ACommand(string&& mnemonic)
        : mnemonic_(std::move(mnemonic))
    {
        auto& fabric = FabricModule<16>::get_instance();
        symbol_table_ = fabric.get_symbol_table();
    }

    std::string execute() override
    {
        if(Helper::is_digit(mnemonic_))
            return std::bitset<16>(stoi(mnemonic_)).to_string();

        if(!symbol_table_->contains(mnemonic_))
            symbol_table_->add_entry(mnemonic_, a_counter_++);

        return std::bitset<16>(symbol_table_->address(mnemonic_)).to_string();
    }
};
