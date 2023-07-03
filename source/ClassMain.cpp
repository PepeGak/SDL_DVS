#include "ClassMain.hpp"

ClassMain::ClassMain()
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassMain::ClassMain()\n";
#endif

    this->appRunning = true;
}

ClassMain::~ClassMain()
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassMain::~ClassMain()\n";
#endif
}

int ClassMain::onExecute()
{
#ifdef _DVS_DEBUG_
    std::cout << "int ClassMain::onExecute()\n";
#endif

    if (!this->onInit())
    {
        std::cout << "onInit() error " << SDL_GetError() << "\n";
        this->onQuit();
        return -1;
    }

    SDL_Event even;
    while (this->appRunning)
    {
        while (SDL_PollEvent(&even))
            this->onEvent(&even);

        this->onRender();
        this->onLoop();
    }

    this->onQuit();

    return 0;
}
