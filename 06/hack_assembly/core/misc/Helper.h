#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <xstring>
#include <filesystem>
using namespace std::filesystem;


#include "../errors/HelperError.h"

using namespace std;

class helper
{
    static void ltrim(std::string& s)
    {
        s.erase(s.begin(),
                std::find_if(s.begin(),
                             s.end(),
                             [](int ch)
                             {
                                 return !std::isspace(ch);
                             }));
    }


    static void rtrim(std::string& s)
    {
        s.erase(std::find_if(s.rbegin(),
                             s.rend(),
                             [](int ch)
                             {
                                 return !std::isspace(ch);
                             }).base(),
                s.end());
    }


public:
    static ifstream process_source(const std::filesystem::path input)
    {
        if(!exists(input))
            throw helper_error("Input file doesn't exist");

        if(!input.has_extension() || input.extension() != ".asm")
            throw helper_error("Input file has unknown extension.\n Please use *.asm.");

        if(filesystem::is_empty(input))
            throw helper_error("Input file is empty");

        return ifstream(input.c_str());
    }

    static std::vector<std::string> split(const std::string& s, char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while(std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    static void remove_comment(string& s)
    {
        auto pos = s.find("//");
        if(pos != string::npos)
            s.erase(pos);
    }

    static void trim(std::string& s)
    {
        ltrim(s);
        rtrim(s);
    }

    static bool is_comment(const string& s)
    {
        return s[0] == '/' && s[1] == '/';
    }
};
