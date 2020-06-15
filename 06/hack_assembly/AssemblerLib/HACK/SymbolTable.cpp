#include "SymbolTable.h"

void SymbolTable::AddEntry(const std::string symbol, const int address)
{
    if(symbol.empty())
        throw "Symbol is empty";
    symbol_table_[symbol] = address;
}

bool SymbolTable::Contains(const std::string symbol)
{
    return symbol_table_.count(symbol) > 0;
}

int SymbolTable::GetAddress(const std::string symbol)
{
    if(!Contains(symbol))
        throw "Symbol doesn't exist in table";

    return symbol_table_[symbol];
}
