#include "ClassMain.hpp"

int main(int argc, char* args[])
{
#ifdef _DVS_DEBUG_
    std::cout << "int main(int, char*)\n";
#endif

    ClassMain engine;
    return engine.onExecute();
}