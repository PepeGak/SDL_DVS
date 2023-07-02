#include "ClassEvent.hpp"

ClassEvent::ClassEvent() {}

ClassEvent::~ClassEvent() {}

void ClassEvent::onEvent(SDL_Event *ev)
{
    switch (ev->type)
    {
    case SDL_QUIT:
        this->onExit();
        break;
    
    default:
        break;
    }
}
