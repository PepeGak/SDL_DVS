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

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer);

    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    ClassRenderer::Draw(this->renderer, some_points, 10);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    ClassRenderer::Draw(this->renderer, this->en->GetPart(0));
    ClassRenderer::Draw(this->renderer, this->en->GetPart(1));

    SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    
    SDL_Rect where = {50, 50, 32, 16};
    SDL_Colour colour = {0, 255, 0};
    ClassRenderer::Draw(this->renderer, this->font, "Hi!", where, colour);

    SDL_RenderPresent(this->renderer);
}
