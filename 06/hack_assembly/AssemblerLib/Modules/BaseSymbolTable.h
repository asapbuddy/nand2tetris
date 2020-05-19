#pragma once
#include <unordered_map>

#include "../API/ISymbolTable.h"

using namespace std;

class BaseSymbolTable : public ISymbolTable
{
    unordered_map<string, int> symbol_table_;
public:
    void add_entry(std::string symbol, int address) override;
    bool contains(std::string symbol) override;
    int address(std::string symbol) override;
};
