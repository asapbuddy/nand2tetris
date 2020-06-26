#include "Assembler.h"
#include "AssemblyParser.h"

void TwoPassAssembler::ProcessLabels(const SourceCodeFile& sourceCode) const
{
    AssemblyParser parser(sourceCode.GetFileInputStream());

    while(parser.HasMoreCommands())
    {
        parser.Advance();
        auto command = parser.ProduceStatement();
        const auto commandType = command->GetCommandType();

        if(command->GetCommandType() == CommandType::label)
            command->Process(*context_);

        if(commandType == CommandType::address || commandType == CommandType::instruction)
            context_->IncreaseInstructionCounter();
    }
}

void TwoPassAssembler::ProcessInstructions(const SourceCodeFile& sourceCode)
{
    AssemblyParser parser(sourceCode.GetFileInputStream());

    while(parser.HasMoreCommands())
    {
        parser.Advance();
        auto command = parser.ProduceStatement();
        const auto commandType = command->GetCommandType();

        if(commandType == CommandType::address || commandType == CommandType::instruction)
        {
            command->Process(*context_);
            result_.emplace_back(command->GetResult());
        }
    }
}

void TwoPassAssembler::Compile(SourceCodeFile sourceCodeFile)
{
    ProcessLabels(sourceCodeFile);
    ProcessInstructions(sourceCodeFile);
}

std::vector<std::string> TwoPassAssembler::GetCompilationResults()
{
    return result_;
}
