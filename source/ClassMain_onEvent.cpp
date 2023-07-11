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

void ClassMain::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)\n";
#endif
    switch(sym)
    {
    case SDLK_q:
        if (this->menu_options == ClassMain::MenuList::ENGINE_SCREEN)
            this->menu_options = ClassMain::MenuList::HELP_TEXT;
        else if (this->menu_options == ClassMain::MenuList::HELP_TEXT)
            this->menu_options = ClassMain::MenuList::ENGINE_SCREEN;
        break;
    
    }
}

void ClassMain::onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode)\n";
#endif

}

void ClassMain::onLMouseDown(Sint32 xm, Sint32 ym)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onLMouseDown(Sint32 xm, Sint32 ym)\n";
#endif
    
}
