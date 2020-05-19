#pragma once
#include <sstream>
#include <string>
#include <vector>

struct Helper
{
    static std::vector<std::string> split(const std::string& s, const char delimiter)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream token_stream(s);

        while(std::getline(token_stream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
};
