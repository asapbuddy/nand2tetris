#include "BaseCodeModule.h"

#include <bitset>

std::bitset<3> BaseCodeModule::dest(std::string mnemonic)
{
    return std::bitset<3>("000");
}

std::bitset<7> BaseCodeModule::comp(std::string mnemonic)
{
    return std::bitset<7>("0000000");
}

std::bitset<3> BaseCodeModule::jump(std::string mnemonic)
{
    if(1 == 1)
        return std::bitset<3>("000");
}
