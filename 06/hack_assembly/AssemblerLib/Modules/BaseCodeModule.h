#pragma once
#include "../API/ICodeModule.h"

class BaseCodeModule : public ICodeModule
{
public:
    std::bitset<3> dest(std::string mnemonic) override;
    std::bitset<7> comp(std::string mnemonic) override;
    std::bitset<3> jump(std::string mnemonic) override;
};
