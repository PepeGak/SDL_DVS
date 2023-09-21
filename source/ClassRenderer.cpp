#include "ClassRenderer.hpp"

void ClassRenderer::DrawLinesF(SDL_Renderer *renderer, const SDL_FPoint points[], const Sint32 amount)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, SDL_FPoint*, Sint32)\n";
#endif
    if (!renderer || !points)
        return;

    SDL_RenderDrawLinesF(renderer, points, amount);
}

void ClassRenderer::DrawLines(SDL_Renderer *renderer, const SDL_Point points[], const Sint32 amount)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawLines(SDL_Renderer*, const SDL_Point*, const Sint32)\n";
#endif
    if (!renderer || !points)
        return;

    SDL_RenderDrawLines(renderer, points, amount);
}

void ClassRenderer::DrawRectF(SDL_Renderer *renderer, const SDL_FRect rect, const SDL_Color colour)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawRect(SDL_Renderer *, const SDL_Rect, const SDL_Color)\n";
#endif

    if (!renderer)
        return;
    
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRectF(renderer, &rect);
}

void ClassRenderer::DrawCircle(SDL_Renderer *renderer, const SDL_FPoint centre, const Sint32 p,
                               const Uint32 phi_beg, const Uint32 phi_end = 0)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawCircle(SDL_Renderer*, SDL_Point, Sint32, Uint32, Uint32)\n";
#endif

    if (!renderer)
        return;

    SDL_FPoint *circle = new SDL_FPoint[phi_end - phi_beg + 1];
    for (Sint32 a = phi_beg; a <= phi_end; a++)
    {
        circle[a - phi_beg].x = centre.x + p * SDL_cosf(2 * M_PI * a / 360);
        circle[a - phi_beg].y = centre.y - p * SDL_sinf(2 * M_PI * a / 360);
    }
    SDL_RenderDrawLinesF(renderer, circle, phi_end - phi_beg + 1);
    delete[] circle;
    circle = nullptr;
}

void ClassRenderer::DrawEllips(SDL_Renderer *renderer, const SDL_FPoint centre,
                               const Sint32 a, const Sint32 b, const Uint32 phi_beg,
                               const Uint32 phi_end)
{
    if (!renderer)
        return;

    SDL_FPoint *ellips = new SDL_FPoint[phi_end - phi_beg + 1];
    SDL_memset(ellips, 0, phi_end - phi_beg + 1);
    for (Uint32 phi = phi_beg; phi <= phi_end; phi++)
    {
        ellips[phi - phi_beg].x = centre.x + a * SDL_cosf(phi * 2 * M_PI / 360);
        ellips[phi - phi_beg].y = centre.y - b * SDL_sinf(phi * 2 * M_PI / 360);
    }
    SDL_RenderDrawLinesF(renderer, ellips, phi_end - phi_beg + 1);
    delete[] ellips;
    ellips = nullptr;
}

void ClassRenderer::DrawText(SDL_Renderer *renderer, TTF_Font *font, const char *string, const SDL_Rect where)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawText(SDL_Renderer*, TTF_Font*, const char*, const SDL_Rect)\n";
#endif
    if (!renderer || !font || !string)
        return;

    SDL_Color fg;
    SDL_GetRenderDrawColor(renderer, &fg.r, &fg.g, &fg.b, &fg.a);
    SDL_Surface *textSurface = TTF_RenderUTF8_Solid(font, string, fg);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface); textSurface = nullptr;

    SDL_RenderCopy(renderer, textTexture, nullptr, &where);
    SDL_DestroyTexture(textTexture); textTexture = nullptr;
}

void ClassRenderer::DrawText(SDL_Renderer *renderer, TTF_Font *font, const char *string, const Sint32 x, const Sint32 y)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawText(SDL_Renderer*, TTF_Font*, const char*, const Sint32, const Sint32)\n";
#endif
    if (!renderer || !font || !string)
        return;

    SDL_Color fg;
    SDL_GetRenderDrawColor(renderer, &fg.r, &fg.g, &fg.b, &fg.a);
    SDL_Surface *textSurface = TTF_RenderUTF8_Solid(font, string, fg);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface); textSurface = nullptr;

    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;

    TTF_SizeUTF8(font, string, &dstRect.w, &dstRect.h);

    SDL_RenderCopy(renderer, textTexture, nullptr, &dstRect);
    SDL_DestroyTexture(textTexture); textTexture = nullptr;
}

void ClassRenderer::DrawPart(SDL_Renderer *renderer, const ClassEngine::EnginePart *shape,
                            const SDL_Point where)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::Draw(SDL_Renderer*, const ClassEngine::EnginePart)\n";
#endif

    if (!renderer || !shape)
        return;

    SDL_Rect dstRect;
    dstRect.x = where.x;
    dstRect.y = where.y;
    SDL_QueryTexture(shape->texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
    dstRect.w *= 1.5; dstRect.h *= 1.5;
    SDL_RenderCopy(renderer, shape->texture, nullptr, &dstRect);
}

void ClassRenderer::DrawPart(SDL_Renderer *renderer, const ClassEngine::EnginePart *shape)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawPart(SDL_Renderer *, const EnginePart *)\n";
#endif

    if (!renderer || !shape)
        return;

    SDL_Rect dstRect;
    dstRect.x = shape->x;
    dstRect.y = shape->y;
    SDL_QueryTexture(shape->texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
    dstRect.w *= 1.5; dstRect.h *= 1.5;
    SDL_RenderCopy(renderer, shape->texture, nullptr, &dstRect);
}

void ClassRenderer::DrawPartAngled(SDL_Renderer *renderer, 
                                    const ClassEngine::EnginePart *shape, SDL_Point where, 
                                    float angle, SDL_RendererFlip flip)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawPartAngled(SDL_Renderer *, const EnginePart *, SDL_Point, float, SDL_RendererFlip)\n";
#endif

    if (!renderer || !shape)
        return;
    
    SDL_Rect dstRect;
    dstRect.x = where.x;
    dstRect.y = where.y;
    SDL_QueryTexture(shape->texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
    dstRect.w *= 1.5; dstRect.h *= 1.5;
    SDL_RenderCopyEx(renderer, shape->texture, nullptr, &dstRect, angle, nullptr, flip);
}

void ClassRenderer::DrawPartAngled(SDL_Renderer *renderer, const ClassEngine::EnginePart *shape, float angle, SDL_RendererFlip flip)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawPartAngled(SDL_Renderer *, const EnginePart *, float, SDL_RendererFlip)\n";
#endif

    if (!renderer || !shape)
        return;
    
    SDL_Rect dstRect;
    dstRect.x = shape->x;
    dstRect.y = shape->y;
    SDL_QueryTexture(shape->texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
    dstRect.w *= 1.5; dstRect.h *= 1.5;
    SDL_RenderCopyEx(renderer, shape->texture, nullptr, &dstRect, angle, nullptr, flip);
}

void ClassRenderer::DrawPartAngled(SDL_Renderer *renderer, const ClassEngine::EnginePart *shape, SDL_Point where, SDL_Point *around, float angle, SDL_RendererFlip flip)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassRenderer::DrawPartAngled(SDL_Renderer *renderer, const ClassEngine::EnginePart *, SDL_Point, SDL_Point *, float, SDL_RendererFlip)\n";
#endif

    if (!renderer || !shape)
        return;
    
    SDL_Rect dstRect;
    dstRect.x = where.x;
    dstRect.y = where.y;
    SDL_QueryTexture(shape->texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
    dstRect.w *= 1.5; dstRect.h *= 1.5;
    SDL_RenderCopyEx(renderer, shape->texture, nullptr, &dstRect, angle, around, flip);
}
