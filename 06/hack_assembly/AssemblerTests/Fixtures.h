#pragma once
#include <fstream>
#include <AssemblerLib/HACK/Assembler.h>


namespace assembler_tests
{
    constexpr uint8_t bitness = 16;

    struct Configuration
    {
        std::string tests_path{"..\\AssemblerTests\\Tests\\"};

        std::string locate_test_file(const char* name, const char* ext) const
        {
            std::string result(tests_path);
            result.append(name);
            result.append(ext);
            return result;
        }

        void create_assembly(const std::string& name)
        {
            std::string path(tests_path);
            path.append(name).append(".asm");
            Assembler assembler_module(path.c_str());
            assembler_module.process_labels();
            assembler_module.compile();
            assembler_module.save("hack");
        }

        bool compare_two_files(const std::string& file1, const std::string& file2)
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
