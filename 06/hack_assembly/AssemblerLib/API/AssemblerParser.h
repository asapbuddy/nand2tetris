#pragma once


#include "InstructionStatement.h"
#include "../Core/Global.h"


/**
 * \brief Encapsulates access to the input code. Reads an assembly language com-
    mand, parses it, and provides convenient access to the command’s components
    (fields and symbols). In addition, removes all white space and comments.
 * \ctor Opens the input file/stream and gets ready for parse it.
 */
struct AssemblerParser
{
    virtual ~AssemblerParser() = default;

    /**
     * \brief Reads the next command from the input
        and makes it current command. Should be called if
        has_more_commands() is true.
        Initially there is no current command.
     */
    virtual void Advance() = 0;

    virtual bool HasMoreCommands() = 0;

    /**
     * \brief 
     * \return Encapsulated command
     */
    virtual unique_ptr<InstructionStatement> ProduceCommand() = 0;

    /**
     * \brief Returns the type of current command:
        - a_command for @Xxx where Xxx is either a symbol
            or decimal number
        - c_command for dest = comp;jump
        - l_command (actually, pseudocommand) for
            for (Xxx) where Xxx is a symbol
     * \return a_command, c_command, l_command
     */
    virtual CommandType GetCommandType() = 0;
};
