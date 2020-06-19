#include <iostream>

#include "HackFactory.h"
#include "../API/SourceCodeFile.h"
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
        auto hackFactory = make_unique<HackFactory>();
        auto assembler = hackFactory->CreateAssembler();
        SourceCodeFile sourceCode(argv[1]);
        sourceCode.CheckFile();
        assembler->Compile(sourceCode);
        auto compiled = assembler->GetCompilationResults();
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
