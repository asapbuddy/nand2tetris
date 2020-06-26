#include "NullCommand.h"

void NullCommand::Process(const Context&)
{
    throw "Attempt to processing NullCommand";
}

string NullCommand::GetResult()
{
    throw "Attempt to get result of NullCommand processing";
}

CommandType NullCommand::GetCommandType()
{
    return CommandType::not_command;
}
