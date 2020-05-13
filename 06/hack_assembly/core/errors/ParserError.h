#pragma once
#include <exception>
#include <ostream>
using namespace std;

class parser_error final : public exception
{
public:
    explicit parser_error(const char* message)
        : exception(message)
    {
    }

    friend std::ostream& operator<<(std::ostream& os, const parser_error& obj)
    {
        return os << "Parser Error: " << obj.what() << endl; 
    }
};
