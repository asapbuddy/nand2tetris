#pragma once
#include <bitset>


#include "ProcessingParameters.h"
#include "../../API/Statement.h"
#include "../../API/LookupTable.h"


class Address final : public Statement
{
    string mnemonic_, result_;

public:
    ~Address() override = default;

    Address(string&& mnemonic)
        : mnemonic_(std::move(mnemonic))
    {
    }

    void Process(const StatementParameters& parameters) override
    {
        if(is_digit(mnemonic_))
            result_ = std::bitset<16>(stoi(mnemonic_)).to_string();
        else
            result_ = parameters.DecodeAddress(mnemonic_);
    }

    string GetResult() override
    {
        return result_;
    }

    CommandType GetCommandType() override
    {
        return CommandType::address;
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
