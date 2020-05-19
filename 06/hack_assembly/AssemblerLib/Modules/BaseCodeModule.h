#pragma once
#include <string>
#include <unordered_map>

#include "../API/ICodeModule.h"

using namespace std;

class BaseCodeModule final : public ICodeModule
{
    std::unordered_map<string, string> comp_table_;
    std::unordered_map<string, string> jump_table_;
    std::unordered_map<string, string> dest_table_;

    void init_comp_table();
    void init_jump_table();
    void init_dest_table();
public:

    BaseCodeModule()
    {
        init_comp_table();
        init_jump_table();
        init_dest_table();
    }

    std::bitset<3> dest(std::string mnemonic) override;
    std::bitset<7> comp(std::string mnemonic) override;
    std::bitset<3> jump(std::string mnemonic) override;
    std::bitset<16> instruction() override;
};
