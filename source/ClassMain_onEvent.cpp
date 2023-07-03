#include "ClassMain.hpp"

void ClassMain::onEvent(SDL_Event* ev)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onEvent()\n";
#endif

    ClassMain::ClassEvent::onEvent(ev);
}

void ClassMain::onExit()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onExit()\n";
#endif

    this->appRunning = false;
}
