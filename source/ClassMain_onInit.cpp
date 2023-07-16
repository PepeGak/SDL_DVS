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
                                    1024, 640, SDL_WINDOW_SHOWN);
    if (!this->window)
        return false;

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->renderer)
        return false;

    this->en = new ClassEngine(ClassEngine::EngineType::R4);
    if (!this->en)
        return false;

    SDL_Point centre;
    SDL_GetWindowSize(this->window, &centre.x, &centre.y);
    centre.x /= 2;
    centre.y /= 2; centre.y -= 30;
    const float k = 1.5f;
    this->en->Normalise(centre.x, centre.y, 0);
    this->en->Normalise(centre.x, centre.y - 50 * k, 1);
    this->en->Normalise(centre.x, centre.y - 140 * k, 2);
    this->en->Normalise(centre.x, centre.y, 3);
    this->en->Normalise(centre.x, centre.y + 30 * k, 4);
    this->en->Scale(k);

    this->font = TTF_OpenFont("./assets/fonts/arialmt.ttf", 20);
    if (!this->font)
        return false;

    return true;
}