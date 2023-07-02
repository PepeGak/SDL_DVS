#include "ClassMain.hpp"

void ClassMain::onEvent(SDL_Event* ev)
{
    ClassMain::ClassEvent::onEvent(ev);
}

void ClassMain::onExit()
{
    this->appRunning = false;
}
