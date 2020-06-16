#pragma once
#include <bitset>

#include "../../API/InstructionStatement.h"
#include "../../API/LookupTable.h"
#include "../../Core/FabricModule.h"


class Address : public InstructionStatement
{
    string mnemonic_, result_;

    inline static unsigned a_counter_ = 16;
    LookupTable& symbol_table_;


public:
    ~Address() override = default;

    Address(string&& mnemonic)
        : mnemonic_(std::move(mnemonic)),
          symbol_table_(FabricModule::get_symbol_table())
    {
    }

    void Process() override
    {
        if(is_digit(mnemonic_))
            result_ = std::bitset<16>(stoi(mnemonic_)).to_string();
        else
        {
            if(!symbol_table_.Contains(mnemonic_))
                symbol_table_.AddEntry(mnemonic_, a_counter_++);

            result_ = std::bitset<16>(symbol_table_.GetAddress(mnemonic_)).to_string();
        }
    }

    string GetResult() override
    {
        return result_;
    }

    CommandType GetCommandType() override
    {
        return CommandType::a_command;
    }

private:
    static bool is_digit(std::string& s)
    {
        for(auto ch : s)
        {
            if(!std::isdigit(ch))
                return false;
        }
        return true;
    }
};
