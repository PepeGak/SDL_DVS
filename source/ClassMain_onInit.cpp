#include "ClassMain.hpp"

bool ClassMain::onInit()
{
#ifdef _DVS_DEBUG_
    std::cout << "bool ClassMain::onInit()\n";
#endif

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
    if (TTF_Init() < 0)
        return false;
    if (IMG_Init(IMG_INIT_PNG) == 0)
        return false;

    this->window = SDL_CreateWindow("SDL_DVS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    640, 480, SDL_WINDOW_SHOWN);
    if (!this->window)
        return false;

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->renderer)
        return false;

    this->en = new ClassEngine(ClassEngine::EngineType::R4);
    if (!this->en)
        return false;
    
    SDL_FPoint centreF;
    SDL_Point centre;
    SDL_GetWindowSize(this->window, &centre.x, &centre.y);
    centre.x /= 2; centre.y /= 2;
    centreF = {centre.x, centre.y};
    this->en->Normalise(centreF.x, centreF.y, 0);
    this->en->Normalise(centreF.x, centreF.y - 30, 1);

    this->font = TTF_OpenFont("./assets/fonts/arialmt.ttf", 16);
    if (!this->font)
        return false;

    return true;
}