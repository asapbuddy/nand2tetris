#pragma once
#include <string>


#include "ICommand.h"
#include "../Core/Global.h"


/**
 * \brief Encapsulates access to the input code. Reads an assembly language com-
    mand, parses it, and provides convenient access to the command’s components
    (fields and symbols). In addition, removes all white space and comments.
 * \ctor Opens the input file/stream and gets ready for parse it.
 */
struct IParserModule
{
    virtual ~IParserModule() = default;


    /**
     * \brief ctor replacement
     * \param path to assembly source file
     * \return true if initialized correctly
     */
    virtual void init(const char* path) = 0;

    /**
     * \brief Reads the next command from the input
        and makes it current command. Should be called if
        has_more_commands() is true.
        Initially there is no current command.
     */
    virtual bool advance() = 0;

    
    /**
     * \brief 
     * \return Encapsulated command
     */
    virtual ICommand* get_command() = 0;

    /**
     * \brief Returns the type of current command:
        - a_command for @Xxx where Xxx is either a symbol
            or decimal number
        - c_command for dest = comp;jump
        - l_command (actually, pseudocommand) for
            for (Xxx) where Xxx is a symbol
     * \return a_command, c_command, l_command
     */
    virtual CommandType command_type() = 0;

    virtual void reset() = 0;
};
