#include <iostream>

#include "../AssemblerLib/Core/DefaultModuleFabric.h"
#include "../AssemblerLib/Modules/AssemblerModule.h"
#include "../core/Parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    const uint8_t bitness = 16;

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
        AssemblerModule<bitness> assembler(argv[1]);
        assembler.init();
        assembler.process_labels();
        assembler.compile();
        assembler.save("hack");
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
