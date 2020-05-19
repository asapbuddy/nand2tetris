
#include "../AssemblerLib/Core/DefaultModuleFabric.h"

int main(int argc, char* argv[])
{
    IModuleFabric* fabric = new DefaultModuleFabric;

    auto code = fabric->get_code_module();
    
    return 0;
}
