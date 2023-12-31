#include "ClassMain.hpp"

void ClassMain::onQuit()
{
#ifdef _DVS_DEBUG_
    std::cout << "int ClassMain::onQuit()\n";
#endif

    if (this->font)
        TTF_CloseFont(this->font);
    this->font = nullptr;

    if (this->en)
        delete this->en;
    this->en = nullptr;

    if (this->fuel)
        delete this->fuel;
    this->fuel = nullptr;
    
    if (this->renderer)
        SDL_DestroyRenderer(this->renderer);
    this->renderer = nullptr;

    if (this->window)
        SDL_DestroyWindow(this->window);
    this->window = nullptr;

    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
