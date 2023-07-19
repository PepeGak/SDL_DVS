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
    SDL_GetWindowSize(this->window, &center.x, &center.y);
    center.x /= 2; center.y /= 2;

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (!this->renderer)
        return false;

    this->en = new ClassEngine(this->renderer);
    if (!this->en)
        return false;
    
    using PN = ClassEngine::PartNames;
    SDL_Point start_point = {100, 100};
    this->en->SetPartX(PN::ENGINE_BODY, start_point.x); this->en->SetPartY(PN::ENGINE_BODY, start_point.y);
    this->en->SetPartX(PN::PISTON, start_point.x + 46); this->en->SetPartY(PN::PISTON, start_point.y + 130);
    this->en->SetPartX(PN::CRANK, start_point.x + 60); this->en->SetPartY(PN::CRANK, start_point.y + 180);
    this->en->SetPartX(PN::LINK_ROD, start_point.x + 67); this->en->SetPartY(PN::LINK_ROD, start_point.y + 135);

    this->font = TTF_OpenFont("./assets/fonts/arialmt.ttf", 22);
    if (!this->font)
        return false;

    return true;
}