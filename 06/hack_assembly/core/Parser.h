#pragma once
#include <filesystem>
#include <fstream>
using namespace std;
using namespace std::filesystem;

#include "errors/ParserError.h"

class parser
{
    ifstream input_file_;
    ofstream output_file_;

public:
    parser(ifstream&& in, char* out)
        : input_file_(std::move(in)), output_file_(out)
    {
    }


    void throw_exception()
    {
        throw parser_error("Test exception method");
    }
};
