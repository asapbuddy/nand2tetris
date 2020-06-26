#pragma once
#include <unordered_map>


#include "../API/LookupTable.h"


using namespace std;

class SymbolTable final : public LookupTable
{
    unordered_map<string, int> symbol_table_;

    void init_sym_table();

public:
    SymbolTable()
    {
        init_sym_table();
    }

    void AddEntry(std::string symbol, int address) override;
    bool Contains(std::string symbol) override;
    int GetAddress(std::string symbol) override;
};
