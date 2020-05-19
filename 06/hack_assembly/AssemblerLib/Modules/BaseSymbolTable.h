#pragma once
#include "../API/ISymbolTable.h"

class BaseSymbolTable : public ISymbolTable
{
public:
    void add_entry(std::string symbol, int address) override;
    bool contains(std::string symbol) override;
    int address(std::string symbol) override;
};
