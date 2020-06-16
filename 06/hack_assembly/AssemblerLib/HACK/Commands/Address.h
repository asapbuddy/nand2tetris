#pragma once
#include <bitset>


#include "StatementParameters.h"
#include "../../API/Statement.h"
#include "../../API/LookupTable.h"
#include "../../Core/FabricModule.h"


class Address : public Statement
{
    string mnemonic_, result_;
    StatementParameters& parameters_;

public:
    ~Address() override = default;

    Address(string&& mnemonic, StatementParameters& parameters)
        : mnemonic_(std::move(mnemonic)),
          parameters_(parameters)

    {
    }

    void Process() override
    {
        if(is_digit(mnemonic_))
            result_ = std::bitset<16>(stoi(mnemonic_)).to_string();
        else
        {
            auto symbol_table = parameters_.GetLookupTable();

            if(!symbol_table->Contains(mnemonic_))
            {
                const auto offset = parameters_.GetNextAddressOffset();
                symbol_table->AddEntry(mnemonic_, offset);
            }

            result_ = std::bitset<16>(symbol_table->GetAddress(mnemonic_)).to_string();
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
