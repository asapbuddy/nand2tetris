#pragma once
#include <string>

#include "../../API/InstructionParts.h"
#include "../../API/Statement.h"


class Instruction final : public Statement
{
    InstructionParts parts_;
    std::string result_;

public:
    ~Instruction() override;

    explicit Instruction(InstructionParts&& dto);

    void Process(const Context& parameters) override;

    string GetResult() override;

    CommandType GetCommandType() override;
};
