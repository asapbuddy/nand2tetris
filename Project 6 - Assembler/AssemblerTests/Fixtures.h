#pragma once
#include <fstream>


#include "Project 6 - Assembler/API/BinaryCodeFile.h"
#include "Project 6 - Assembler/API/InstructionParts.h"
#include "Project 6 - Assembler/API/SourceCodeFile.h"
#include "Project 6 - Assembler/Assembler/HackFactory.h"


namespace assembler_tests
{
    using namespace std;
    constexpr uint8_t bitness = 16;

    struct Configuration
    {
        std::string TestsPath{"..\\Project 6 - Assembler\\AssemblerTests\\AssemblerTests\\"};


        static InstructionParts dest(const string& dest)
        {
            return {dest, "", ""};
        }

        static InstructionParts comp(const string& comp)
        {
            return {"", comp, ""};
        }

        static InstructionParts jump(const string& jump)
        {
            return {"", "", jump};
        }


        std::string locate_test_file(const char* name, const char* ext) const
        {
            auto result(TestsPath);
            result.append(name);
            result.append(ext);
            return result;
        }

        void create_assembly(const std::string& name) const
        {
            auto inputFile(TestsPath);
            inputFile.append(name).append(".asm");
            auto outputFile(TestsPath);
            outputFile.append(name).append(".hack");
            SourceCodeFile sourceCode(inputFile.c_str());
            BinaryCodeFile binaryCode(outputFile.c_str());
            auto hackFactory = make_unique<HackFactory>();
            auto assembler = hackFactory->CreateAssembler();
            sourceCode.CheckFile();
            assembler->Compile(sourceCode);
            const auto compiled = assembler->GetCompilationResults();
            binaryCode.WriteAllLines(compiled);
        }

        bool compare_two_files(const std::string& file1, const std::string& file2) const
        {
            std::ifstream f1(file1, std::ifstream::binary | std::ifstream::ate);
            std::ifstream f2(file2, std::ifstream::binary | std::ifstream::ate);

            if(f1.fail() || f2.fail())
            {
                return false; //file problem
            }

            if(f1.tellg() != f2.tellg())
            {
                return false; //size mismatch
            }

            //seek back to beginning and use std::equal to compare contents
            f1.seekg(0, std::ifstream::beg);
            f2.seekg(0, std::ifstream::beg);
            return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                              std::istreambuf_iterator<char>(),
                              std::istreambuf_iterator<char>(f2.rdbuf()));
        }

        ~Configuration() = default;
    };
} // namespace tests
