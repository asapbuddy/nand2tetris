#pragma once

#include "../../API/InstructionStatement.h"
#include "../../API/LookupTable.h"

class Label : public InstructionStatement
{
    std::string mnemonic_;
    LookupTable* symbol_table_ = nullptr;
public:
    ~Label() override = default;

    Label(string&& mnemonic)
        : mnemonic_(std::move(mnemonic))
    {
    }


    string Decode() override
    {
        return mnemonic_;
    }
};
