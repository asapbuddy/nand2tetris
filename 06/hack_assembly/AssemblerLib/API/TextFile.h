#pragma once
#include <exception>

struct TextFile
{
    virtual ~TextFile() = default;

    virtual bool CanRead() = 0;

    virtual bool HasError() = 0;

    virtual std::exception GetError() = 0;
};
