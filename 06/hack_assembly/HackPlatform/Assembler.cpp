#include "Assembler.h"
#include "Parser.h"

void TwoPassAssembler::ProcessLabels(SourceCodeFile sourceCode) const
{
    Parser parser(sourceCode.GetFileInputStream());

    while(parser.HasMoreCommands())
    {
        parser.Advance();
        auto command = parser.ProduceStatement();
        const auto commandType = command->GetCommandType();

        if(command->GetCommandType() == CommandType::label)
            command->Process(*parameters_);

        if(commandType == CommandType::address || commandType == CommandType::instruction)
            parameters_->IncreaseInstructionCounter();
    }
}

void TwoPassAssembler::ProcessInstructions(SourceCodeFile sourceCode)
{
    Parser parser(sourceCode.GetFileInputStream());

    while(parser.HasMoreCommands())
    {
        parser.Advance();
        auto command = parser.ProduceStatement();
        const auto commandType = command->GetCommandType();

        if(commandType == CommandType::address || commandType == CommandType::instruction)
        {
            command->Process(*parameters_);
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

/*
void TwoPassAssembler::SaveBinary()
{
    const std::string fn(file_path_);
    const auto dot = fn.rfind('.', fn.length());

    const auto outputFn = dot == std::string::npos ? fn + "hack" : fn.substr(0, dot + 1) + "hack";
    std::ofstream outputFile(outputFn);
    const ostream_iterator<std::string> outputIterator(outputFile, "\n");
    std::copy(result_.begin(), result_.end(), outputIterator);
    outputFile.close();
}
*/
