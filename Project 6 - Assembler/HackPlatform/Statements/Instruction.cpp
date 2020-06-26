#include "Instruction.h"

Instruction::~Instruction() = default;

Instruction::Instruction(InstructionParts&& dto)
    : parts_(dto)
{
}

void Instruction::Process(const Context& parameters)
{
    result_ = parameters.DecodeInstruction(parts_);
}

string Instruction::GetResult()
{
    return result_;
}

CommandType Instruction::GetCommandType()
{
    return CommandType::instruction;
}
