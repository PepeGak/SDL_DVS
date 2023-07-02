#include "ClassMain.hpp"

void ClassMain::onQuit()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
