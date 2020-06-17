#pragma once

#include "../../API/Statement.h"
#include "../../API/LookupTable.h"

class Label final : public Statement
{
    std::string mnemonic_;
    StatementParameters& parameters_;
public:
    ~Label() override = default;

    Label(string&& mnemonic, StatementParameters& parameters)
        : mnemonic_(mnemonic),
          parameters_(parameters)
    {
    }


    void Process() override
    {
        auto symbol_table_ = parameters_.GetLookupTable();
        const auto current_address = parameters_.GetInstructionCounter();
        symbol_table_->AddEntry(mnemonic_, current_address);
    }

    string GetResult() override
    {
        throw "I haven't result";
    }

    CommandType GetCommandType() override
    {
        return CommandType::label;
    }
};
