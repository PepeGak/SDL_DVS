#include "ClassMain.hpp"

void ClassMain::onRender()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender()\n";
#endif

    SDL_Point some_points[10] =
        {
            {10, 10},
            {10, 15},
            {15, 50},
            {50, 60},
            {90, 20},
            {80, 50},
            {50, 240},
            {500, 40},
            {40, 470},
            {10, 10}};
    
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    ClassRenderer::Draw(this->renderer, some_points, 10);

    SDL_RenderPresent(this->renderer);
}
