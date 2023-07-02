#include "ClassMain.hpp"

ClassMain::ClassMain()
{
    this->appRunning = true;
}

ClassMain::~ClassMain()
{
}

int ClassMain::onExecute()
{
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
