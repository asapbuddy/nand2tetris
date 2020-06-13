#pragma once

#include "../../API/Command.h"
#include "../../API/LookupTable.h"

class Label : public Command
{
    std::string mnemonic_;
    LookupTable* symbol_table_ = nullptr;
public:
    ~Label() override = default;

    Label(string&& mnemonic)
        : mnemonic_(std::move(mnemonic))
    {
    }


    std::string execute() override
    {
        return mnemonic_;
    }
};
