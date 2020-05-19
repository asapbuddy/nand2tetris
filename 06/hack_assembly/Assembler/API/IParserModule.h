#pragma once
#include <string>

enum class CommandType
{
    a_command,
    c_command,
    l_command
};

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
     * \brief Are the more commands in the input?
     * \return true if more commands available in source
     */
    virtual bool has_more_commands() = 0;

    /**
     * \brief Reads the next command from the input
        and makes it current command. Should be called if
        has_more_commands() is true.
        Initially there is no current command.
     */
    virtual void advance() = 0;

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

    /**
     * \brief Should be called only if command_type() returns
        a_command or c_command
     * \return Returns the symbol or decimal of current command
     */
    virtual std::string symbol() = 0;

    /**
    * \brief when command_type() is c_command;
    * \return dest mnemonic of current c_command
    */
    virtual std::string dest() = 0;

    /**
    * \brief when command_type() is c_command;
    * \return comp mnemonic of current c_command
    */
    virtual std::string comp() = 0;

    /**
    * \brief when command_type() is c_command;
    * \return jump mnemonic of current c_command
    */
    virtual std::string jump() = 0;
};
