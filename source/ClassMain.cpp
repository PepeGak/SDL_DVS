#include "ClassMain.hpp"

ClassMain::ClassMain()
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassMain::ClassMain()\n";
#endif

    this->en = nullptr;
    this->fuel = nullptr;
    this->appRunning = true;
    this->window = nullptr;
    this->renderer = nullptr;
    this->center = {0, 0};
    this->mus = nullptr;
    this->animation_on = false;
    this->kW = true;
    this->FPS = 60;
    this->frameDelay = 1000 / FPS;
    this->frameStart = this->frameTime = 0;
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
        this->frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&even))
            this->onEvent(&even);

        this->onLoop();
        this->onRender();

        this->frameTime = SDL_GetTicks() - this->frameStart;
        if (this->frameDelay > this->frameTime)
            SDL_Delay(this->frameDelay - this->frameTime);
    }

    this->onQuit();

    return 0;
}
