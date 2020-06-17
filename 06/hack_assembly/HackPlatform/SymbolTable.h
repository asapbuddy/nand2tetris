﻿#pragma once
#include <unordered_map>


#include "../API/LookupTable.h"


using namespace std;

class SymbolTable final : public LookupTable
{
    unordered_map<string, int> symbol_table_;

    void init_sym_table()
    {
        symbol_table_["SP"] = 0;
        symbol_table_["LCL"] = 1;
        symbol_table_["ARG"] = 2;
        symbol_table_["THIS"] = 3;
        symbol_table_["THAT"] = 4;
        symbol_table_["SCREEN"] = 16384;
        symbol_table_["KBD"] = 24576;

        symbol_table_["R0"] = 0;
        symbol_table_["R1"] = 1;
        symbol_table_["R2"] = 2;
        symbol_table_["R3"] = 3;
        symbol_table_["R4"] = 4;
        symbol_table_["R5"] = 5;
        symbol_table_["R6"] = 6;
        symbol_table_["R7"] = 7;
        symbol_table_["R8"] = 8;
        symbol_table_["R9"] = 9;
        symbol_table_["R10"] = 10;
        symbol_table_["R11"] = 11;
        symbol_table_["R12"] = 12;
        symbol_table_["R13"] = 13;
        symbol_table_["R14"] = 14;
        symbol_table_["R15"] = 15;
    }

public:
    SymbolTable()
    {
        init_sym_table();
    }

    void AddEntry(std::string symbol, int address) override;
    bool Contains(std::string symbol) override;
    int GetAddress(std::string symbol) override;
};