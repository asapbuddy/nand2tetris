﻿#pragma once
#include <sstream>
#include <stdbool.h>
#include <string>
#include <vector>


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

    static void remove_comment(std::string& s)
    {
        auto pos = s.find("//");
        if(pos != std::string::npos)
            s.erase(pos);
    }

    static void trim(std::string& s)
    {
        ltrim(s);
        rtrim(s);
    }

    static bool is_digit(const string& s)
    {
        for(const auto ch : s)
        {
            if(ch < '0' || ch > '0')
                return false;
        }
        return true;
    }
};
