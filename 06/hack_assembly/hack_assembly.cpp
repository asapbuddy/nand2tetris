#include <iostream>

#include "core/Parser.h"
#include "core/errors/HelperError.h"
#include "core/errors/ParserError.h"
#include "core/misc/Helper.h"
using namespace std;
int print_usage();

int main(int argc, char* argv[])
{
    if(argc < 3)
        return print_usage();

    try
    {
        auto&& ifs = helper::process_source(argv[1]);
        parser parser(std::move(ifs), argv[2]);
    }
    catch(helper_error& err)
    {
        cerr << err;
    }
    catch(parser_error& err)
    {
        cerr << err;
    }

    return 0;
}


int print_usage()
{
    cerr << "You have entered wrong number of argumens" << endl;
    cerr << "Use hack_assembly.exe input.hack output.bin" << endl;
    return -1;
}
