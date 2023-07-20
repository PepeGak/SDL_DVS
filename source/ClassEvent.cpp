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

void ClassEvent::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassEvent::onKeyDown(SDL_Keycode, Uint16, Uint16)\n";
#endif

    switch (sym)
    {
    case SDLK_h:
        this->onKeyHDown();
        break;
    case SDLK_DOWN:
        this->onArrowDownDown();
        break;
    case SDLK_UP:
        this->onArrowUpDown();
        break;

    default:
        break;
    }

}

void ClassEvent::onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassEvent::onKeyUp(SDL_Keycode, Uint16, Uint16)\n";
#endif

}
