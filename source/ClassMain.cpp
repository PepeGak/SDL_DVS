#include "ClassMain.hpp"

ClassMain::ClassMain()
{
}

ClassMain::~ClassMain()
{
}

int ClassMain::onExecute()
{
    return 0;
}

bool ClassMain::onInit()
{
    return false;
}

void ClassMain::onEvent(SDL_Event *ev)
{
    ClassEvent::onEvent(ev);
}

void ClassMain::onRender()
{
}

void ClassMain::onLoop()
{
}

void ClassMain::onQuit()
{
}
