#pragma once
#include <bitset>

#include "../../API/InstructionStatement.h"
#include "../../API/LookupTable.h"
#include "../../Core/FabricModule.h"


class Address : public InstructionStatement
{
    string mnemonic_, result_;

    thread_local inline static int a_counter_ = 16;
    LookupTable* const symbol_table_;


public:
    ~Address() override = default;

    Address(string&& mnemonic, LookupTable* const lookup_table)
        : mnemonic_(std::move(mnemonic)),
          symbol_table_(lookup_table)

    {
    }

    void Process() override
    {
        static int counter = 16;
        if(is_digit(mnemonic_))
            result_ = std::bitset<16>(stoi(mnemonic_)).to_string();
        else
        {
            if(!symbol_table_->Contains(mnemonic_))
                symbol_table_->AddEntry(mnemonic_, counter++);

            result_ = std::bitset<16>(symbol_table_->GetAddress(mnemonic_)).to_string();
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
