#pragma once
#include <bitset>
#include <fstream>
#include <iterator>
#include <vector>

#include "../API/IParserModule.h"
#include "../Core/DefaultModuleFabric.h"
#include "../Core/Helper.h"

class Assembler
{
    const char* file_path_;
    IParserModule* parser_ = nullptr;
    std::vector<std::string> result_;


public:
    Assembler(const char* path)
        : file_path_(path)
    {
        FabricModule& fabric = FabricModule::get_instance();
        parser_ = fabric.get_parser_module();
    }

    ~Assembler() = default;

    void init() const;

    void process_labels() const;

    void compile();

    void save(const char* ext);
};

