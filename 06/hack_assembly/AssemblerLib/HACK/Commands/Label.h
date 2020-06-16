﻿#pragma once

#include "../../API/InstructionStatement.h"
#include "../../API/LookupTable.h"

class Label : public InstructionStatement
{
    std::string mnemonic_;
    int lines_counter_;
    LookupTable* const symbol_table_;
public:
    ~Label() override = default;

    Label(string&& mnemonic, int lines_counter, LookupTable* const lookup_table)
        : mnemonic_(mnemonic),
          lines_counter_(lines_counter),
          symbol_table_(lookup_table)
    {
    }


    void Process() override
    {
        symbol_table_->AddEntry(mnemonic_, lines_counter_);
    }

    string GetResult() override
    {
        throw "I haven't result";
    }

    CommandType GetCommandType() override
    {
        return CommandType::l_command;
    }
};
