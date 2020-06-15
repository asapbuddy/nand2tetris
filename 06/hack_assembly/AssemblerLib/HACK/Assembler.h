#pragma once
#include <bitset>
#include <fstream>
#include <iterator>
#include <vector>

#include "../API/AssemblerParser.h"
#include "../Core/DefaultModuleFabric.h"
#include "../Core/Helper.h"

class Assembler
{
    const char* file_path_;
    std::vector<std::string> result_;


public:
    Assembler(const char* path)
        : file_path_(path)
    {
    }

    ~Assembler() = default;

    void process_labels() const;

    void compile();

    void save(const char* ext);
};
