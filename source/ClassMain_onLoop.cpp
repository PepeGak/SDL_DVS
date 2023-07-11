#include "ClassMain.hpp"

void ClassMain::onLoop()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onLoop()\n";
#endif

    switch (this->menu_options)
    {
    case ClassMain::MenuList::ENGINE_SCREEN:
        
        break;

    case ClassMain::MenuList::HELP_TEXT:
        break;

    default:
        break;
    }
    SDL_Delay(500);
}
