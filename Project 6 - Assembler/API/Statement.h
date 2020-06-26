#pragma once
#include <string>

#include "Context.h"

using namespace std;

enum class CommandType
{
    address,
    instruction,
    label,
    not_command
};

struct Statement
{
    virtual ~Statement() = default;

    /**
     * \brief Hidden Command logic
     */
    virtual void Process(const Context& parameters) = 0;

    /**
     * \brief Call if need
     * \return result after command execution
     */
    virtual string GetResult() = 0;

    /**
    * \brief Returns the type of current command:
    - a_command for @Xxx where Xxx is either a symbol
    or decimal number
    - c_command for dest = comp;jump
    - l_command (actually, pseudo command) for
    for (Xxx) where Xxx is a symbol
    * \return a_command, c_command, l_command
    */
    virtual CommandType GetCommandType() = 0;
};
