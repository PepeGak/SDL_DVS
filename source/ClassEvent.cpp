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

    case SDL_KEYDOWN:
        this->onKeyDown(ev->key.keysym.sym, ev->key.keysym.mod, ev->key.keysym.scancode);
        break;

    case SDL_KEYUP:
        this->onKeyUp(ev->key.keysym.sym, ev->key.keysym.mod, ev->key.keysym.scancode);
        break;

    case SDL_MOUSEBUTTONDOWN:
        switch (ev->button.button)
        {
        case SDL_BUTTON_LEFT:
            this->onLMouseDown(ev->button.x, ev->button.y);
            break;
        
        default:
            break;
        }
        break;

    default:
        break;
    }
}
