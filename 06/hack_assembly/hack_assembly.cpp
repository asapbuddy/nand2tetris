#include <iostream>
#include <iterator>


#include "core/Parser.h"
#include "core/errors/HelperError.h"
#include "core/errors/ParserError.h"
#include "core/misc/Helper.h"
using namespace std;
int print_usage();

int main(int argc, char* argv[])
{
    if(argc != 2)
        return print_usage();

    try
    {
        parser parser;
        parser.load(helper::process_source(argv[1]));
        parser.process();
        auto parsed = parser.compile();

        path output(argv[1]);
        string filename = output.stem().string();
        filename.append(".hack");
        path result(output.parent_path().append(filename));
        std::ofstream output_file(result);

        ostream_iterator<std::string> output_iterator(output_file, "\n");
        std::copy(parsed.begin(), parsed.end(), output_iterator);
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
    cerr << "Use hack_assembly.exe input.asm" << endl;
    return -1;
}
