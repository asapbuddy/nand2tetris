#include "Address.h"

#include <bitset>

Address::~Address() = default;

Address::Address(string&& mnemonic)
    : mnemonic_(std::move(mnemonic))
{
}

void Address::Process(const Context& parameters)
{
    if(is_digit(mnemonic_))
        result_ = std::bitset<16>(stoi(mnemonic_)).to_string();
    else
        result_ = parameters.DecodeAddress(mnemonic_);
}

string Address::GetResult()
{
    return result_;
}

CommandType Address::GetCommandType()
{
    return CommandType::address;
}

bool Address::is_digit(std::string& s)
{
    for(auto ch : s)
    {
        if(!std::isdigit(ch))
            return false;
    }
    return true;
}
