#include "ClassEvent.hpp"

ClassEvent::ClassEvent()
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEvent::ClassEvent()\n";
#endif
}

ClassEvent::~ClassEvent()
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEvent::~ClassEvent()\n";
#endif
}

void ClassEvent::onEvent(SDL_Event *ev)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassEvent::onEvent()\n";
#endif

    switch (ev->type)
    {
    case SDL_QUIT:
        this->onExit();
        break;

    default:
        break;
    }
}
