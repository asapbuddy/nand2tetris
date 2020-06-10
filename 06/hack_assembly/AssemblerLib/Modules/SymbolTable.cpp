#include "SymbolTable.h"

void SymbolTable::add_entry(const std::string symbol, const int address)
{
    if(symbol.empty())
        throw "Symbol is empty";
    symbol_table_[symbol] = address;
}

bool SymbolTable::contains(const std::string symbol)
{
    return symbol_table_.count(symbol) > 0;
}

int SymbolTable::address(const std::string symbol)
{
    if(!contains(symbol))
        throw "Symbol doesn't exist in table";

    return symbol_table_[symbol];
}
