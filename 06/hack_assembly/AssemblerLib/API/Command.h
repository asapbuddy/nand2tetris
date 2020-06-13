#pragma once
#include <string>

using namespace std;

struct Command
{
    virtual ~Command(){};
    virtual string execute() = 0;
};
