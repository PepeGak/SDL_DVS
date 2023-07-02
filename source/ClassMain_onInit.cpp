#include "ClassMain.hpp"

bool ClassMain::onInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
    if (TTF_Init() < 0)
        return false;
    if (IMG_Init(IMG_INIT_PNG) == 0)
        return false;

    return true;
}