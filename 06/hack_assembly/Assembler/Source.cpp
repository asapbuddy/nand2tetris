#include <iostream>


#include "../HackPlatform/Assembler.h"

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
        auto assembler = make_unique<TwoPassAssembler>(argv[1]);
        assembler->process_labels();
        assembler->Compile();
        assembler->SaveBinary();
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
