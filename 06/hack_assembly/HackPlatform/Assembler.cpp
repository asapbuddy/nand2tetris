#include "Assembler.h"

#include <iterator>
#include "Parser.h"
#include "SourceCodeFile.h"

void TwoPassAssembler::process_labels()
{
    SourceCodeFile source_code(file_path_);
    Parser parser(source_code.GetFileStream());

    while(parser.HasMoreCommands())
    {
        parser.Advance();
        auto command = parser.ProduceStatement(statement_parameters_);
        const auto command_type = command->GetCommandType();

        if(command->GetCommandType() == CommandType::label)
            command->Process();

        if(command_type == CommandType::address || command_type == CommandType::instruction)
            statement_parameters_.IncreaseInstructionCounter();
    }
}

void TwoPassAssembler::Compile()
{
    SourceCodeFile source_code(file_path_);
    Parser parser(source_code.GetFileStream());

    while(parser.HasMoreCommands())
    {
        parser.Advance();
        auto command = parser.ProduceStatement(statement_parameters_);
        const auto command_type = command->GetCommandType();

        if(command_type == CommandType::address || command_type == CommandType::instruction)
        {
            command->Process();
            result_.emplace_back(command->GetResult());
        }
    }
}

void TwoPassAssembler::SaveBinary()
{
    const std::string fn(file_path_);
    const auto dot = fn.rfind('.', fn.length());

    const auto output_fn = dot == std::string::npos ? fn + "hack" : fn.substr(0, dot + 1) + "hack";
    std::ofstream output_file(output_fn);
    const ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(result_.begin(), result_.end(), output_iterator);
    output_file.close();
}
