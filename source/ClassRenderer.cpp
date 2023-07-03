#include "ClassRenderer.hpp"

void ClassRenderer::Draw(SDL_Renderer *renderer, SDL_Point points[], Sint32 amount)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, SDL_Point*, Sint32)\n";
#endif

    SDL_RenderDrawLines(renderer, points, amount);
}

void ClassRenderer::Draw(SDL_Renderer *renderer, SDL_Point centre, Sint32 p, Uint32 phi, Uint32 phi_beg)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, SDL_Point, Sint32, Uint32, Uint32)\n";
#endif

}

void ClassRenderer::Draw(SDL_Renderer* renderer, TTF_Font *font, const char *string, SDL_Rect where, SDL_Colour colour)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, TTF_Font*, const char*, SDL_Rect, SDL_Colour)\n";
#endif
    
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, string, colour);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_RenderCopy(renderer, textTexture, nullptr, &where);
    SDL_DestroyTexture(textTexture);
}
