#pragma once
#include <string>

using namespace std;

struct ICommand
{
    virtual ~ICommand(){};
    virtual string execute() = 0;
};
