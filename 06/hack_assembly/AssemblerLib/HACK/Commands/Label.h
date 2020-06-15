#pragma once

#include "../../API/InstructionStatement.h"
#include "../../API/LookupTable.h"

class Label : public InstructionStatement
{
    std::string mnemonic_;
    int lines_counter_;
    LookupTable* symbol_table_ = nullptr;
public:
    ~Label() override = default;

    Label(string&& mnemonic, int lines_counter)
        : mnemonic_(std::move(mnemonic)),
          lines_counter_(lines_counter)
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
