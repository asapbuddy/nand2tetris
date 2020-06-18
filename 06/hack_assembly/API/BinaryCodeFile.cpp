#include "BinaryCodeFile.h"


#include <fstream>
#include <iosfwd>

std::ifstream BinaryCodeFile::GetFileInputStream()
{
    return std::ifstream();
}

std::ofstream BinaryCodeFile::GetFileOutputStream()
{
    return std::ofstream();
}
