#include "ClassRenderer.hpp"

void ClassRenderer::Draw(SDL_Renderer* renderer, const SDL_FPoint points[], const Sint32 amount)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, SDL_FPoint*, Sint32)\n";
#endif
    if (!renderer || !points)
        return;
    
    SDL_RenderDrawLinesF(renderer, points, amount);
}

void ClassRenderer::Draw(SDL_Renderer *renderer, const SDL_Point points[], const Sint32 amount)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, SDL_Point*, Sint32)\n";
#endif
    if (!renderer || !points)
        return;
    
    SDL_RenderDrawLines(renderer, points, amount);
}

void ClassRenderer::Draw(SDL_Renderer* renderer, const SDL_FPoint centre, const Sint32 p, 
    const Uint32 phi, const Uint32 phi_beg = 0)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, SDL_Point, Sint32, Uint32, Uint32)\n";
#endif

    if (!renderer)
        return;

}

void ClassRenderer::Draw(SDL_Renderer* renderer, TTF_Font* font, 
        const char* string, const SDL_Rect where, const SDL_Colour colour)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, TTF_Font*, const char*, SDL_Rect, SDL_Colour)\n";
#endif
    if (!renderer || !font || !string)
        return;

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, string, colour);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_RenderCopy(renderer, textTexture, nullptr, &where);
    SDL_DestroyTexture(textTexture);
}

void ClassRenderer::Draw(SDL_Renderer *renderer, const ClassEngine::EnginePart* shape)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer *renderer, const ClassEngine::EnginePart shape)\n";
#endif
    if (!renderer || !shape)
        return;

    SDL_FPoint* points = new SDL_FPoint[shape->pointAmount];
    SDL_memset(points, 0, shape->pointAmount);
    
    for (Sint32 i = 0; i < shape->pointAmount; i++)
    {
        points[i] = { shape->shape[i].x + shape->centre.x, shape->shape[i].y + shape->centre.y };
    }

    SDL_RenderDrawLinesF(renderer, points, shape->pointAmount);
    delete[] points;
    points = nullptr;
}
