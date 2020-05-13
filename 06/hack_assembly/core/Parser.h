#pragma once
#include <filesystem>
#include <fstream>
#include <xstring>

#include "misc/Helper.h"
using namespace std;
using namespace std::filesystem;

#include "errors/ParserError.h"

class parser
{
    vector<string> source_code;
    ofstream output_file_;

public:

    /**
     * \brief Initialized output file path then do parsing.
     * \param path Where to store parsing results
     */
    explicit parser(char* path)
        : output_file_(path)
    {
    }

    void load(ifstream&& in)
    {
        const string data((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
        auto splitted = helper::split(data, '\n');
        for(auto& s : splitted)
        {
            if(!helper::is_comment(s) && s != "")
            {
                helper::remove_comment(s);
                helper::trim(s);

                source_code.emplace_back(s);
            }
        }
    }

    void preprocess();
};
