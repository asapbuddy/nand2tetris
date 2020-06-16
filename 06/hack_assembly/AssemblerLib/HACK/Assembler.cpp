#include "Assembler.h"

#include <iterator>
#include "Parser.h"
#include "SourceCodeFile.h"

void Assembler::process_labels() 
{
    SourceCodeFile source_code(file_path_);
    Parser parser(source_code.GetFileStream(), statement_parameters_);

    while(parser.HasMoreCommands())
    {
        parser.Advance();
        auto command = parser.ProduceStatement();

        if(command->GetCommandType() == CommandType::l_command)
            command->Process();
    }
}

void Assembler::compile()
{
    SourceCodeFile source_code(file_path_);
    Parser parser(source_code.GetFileStream(), statement_parameters_);

    while(parser.HasMoreCommands())
    {
        parser.Advance();
        auto command = parser.ProduceStatement();
        const auto command_type = command->GetCommandType();

        if(command_type == CommandType::a_command || command_type == CommandType::c_command)
        {
            command->Process();
            result_.emplace_back(command->GetResult());
        }
    }
}

void Assembler::save(const char* ext)
{
    const std::string fn(file_path_);
    auto dot = fn.rfind('.', fn.length());

    const auto output_fn = dot == std::string::npos ? fn + ext : fn.substr(0, dot + 1) + ext;
    std::ofstream output_file(output_fn);
    const ostream_iterator<std::string> output_iterator(output_file, "\n");
    std::copy(result_.begin(), result_.end(), output_iterator);
    output_file.close();
}
