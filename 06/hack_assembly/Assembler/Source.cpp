#include <iostream>

#include "../AssemblerLib/HACK/Assembler.h"

using namespace std;

int main(const int argc, char* argv[])
{
    if(argc < 2)
    {
        cout
            << "Wrong input arguments"
            << "Use Assembler.exe [source.asm]"
            << endl;

        return 0;
    }

    try
    {
        Assembler assembler(argv[1]);
        assembler.process_labels();
        assembler.assemble();
        assembler.save("hack");
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
