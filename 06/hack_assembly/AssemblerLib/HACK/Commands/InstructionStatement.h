#pragma once
#include <string>

using namespace std;

struct InstructionStatement
{
    virtual ~InstructionStatement() = default;
    virtual void Process() = 0;
    virtual string GetResult() = 0;
};
