#pragma once
#include <exception>

using namespace std;

class helper_error final : public exception
{
public:
    explicit helper_error(const char* message)
        : exception(message)
    {
    }
    
    friend std::ostream& operator<<(std::ostream& os, const helper_error& obj)
    {
        return os << "Helper Error: " << obj.what() << endl; 
    }
};
