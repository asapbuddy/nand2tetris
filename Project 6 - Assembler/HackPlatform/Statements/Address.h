#pragma once

#include "../../API/Statement.h"
#include "../../API/LookupTable.h"


class Address final : public Statement
{
    string mnemonic_, result_;

public:
    ~Address() override;

    explicit Address(string&& mnemonic);

    void Process(const Context& parameters) override;

    string GetResult() override;

    CommandType GetCommandType() override;

private:
    static bool is_digit(std::string& s);
};
