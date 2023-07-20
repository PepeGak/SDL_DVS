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

void ClassMain::onLMouseDown(Sint32 xm, Sint32 ym)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onLMouseDown(Sint32, Sint32)\n";
#endif
    
}

void ClassMain::onKeyHDown()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onKeyHDown()\n";
#endif

    if (this->menu_options == ClassMain::MenuList::ENGINE_SCREEN)
        this->menu_options = ClassMain::MenuList::HELP_TEXT;
    else if (this->menu_options == ClassMain::MenuList::HELP_TEXT)
        this->menu_options = ClassMain::MenuList::ENGINE_SCREEN;
}

void ClassMain::onArrowUpDown()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onArrowUpDown()\n";
#endif

    this->en->SetRPM(this->en->GetRPM() + 1);
}

void ClassMain::onArrowDownDown()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onArrowDownDown()\n";
#endif

    this->en->SetRPM(this->en->GetRPM() - 1);
}
