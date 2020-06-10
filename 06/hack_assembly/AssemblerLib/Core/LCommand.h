#pragma once
#include "DefaultModuleFabric.h"
#include "../API/ICommand.h"

class LCommand : public ICommand
{
    std::string mnemonic_;
    ISymbolTable* symbol_table_ = nullptr;
public:
    ~LCommand() override = default;

    LCommand(string&& mnemonic)
        : mnemonic_(std::move(mnemonic))
    {
    }


    std::string execute() override
    {
        return mnemonic_;
    }
};
