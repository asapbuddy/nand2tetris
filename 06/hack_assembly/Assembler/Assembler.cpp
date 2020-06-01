#include <iostream>

#include "../AssemblerLib/Core/DefaultModuleFabric.h"
#include "../AssemblerLib/Modules/BaseAssemblerModule.h"
#include "../core/Parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    const uint8_t bitness = 16;

    IModuleFabric* fabric = new DefaultFabricModule<bitness>;

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
        BaseAssemblerModule<bitness> assembler(argv[1], fabric);
        const auto init_result = assembler.init();
        if(!init_result)
            throw "Assembler initialization has failed";

        assembler.process_labels();
        assembler.compile();
        assembler.save("hack");
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }

    delete fabric;
    return 0;
}
