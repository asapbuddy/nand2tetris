#include "Label.h"

Label::~Label() = default;

Label::Label(string&& mnemonic)
    : mnemonic_(mnemonic)
{
}

void Label::Process(const Context& parameters)
{
    parameters.AddLabel(mnemonic_);
}

string Label::GetResult()
{
    throw "I haven't result";
}

CommandType Label::GetCommandType()
{
    return CommandType::label;
}
