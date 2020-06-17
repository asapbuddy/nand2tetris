#pragma once

struct Assembler
{
    virtual ~Assembler() = default;

    /**
     * \brief compiles source code
     */
    virtual void Compile() = 0;

    /**
     * \brief save compilation results
     */
    virtual void SaveBinary() = 0;
};
