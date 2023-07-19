/*
* Класс, отвечающий за отрисовку различных фигур, текстур и текста
*/
#ifndef _CLASS_RENDERER_HPP_
#define _CLASS_RENDERER_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "ClassEngine.hpp"

class ClassRenderer
{
public:
    static void DrawLinesF(SDL_Renderer* renderer, const SDL_FPoint points[], const Sint32 amount); //Рисовка линий по нескольким точкам
    static void DrawLines(SDL_Renderer* renderer, const SDL_Point points[], const Sint32 amount); //Рисовка линий по нескольким точкам
    static void DrawCircle(SDL_Renderer* renderer, const SDL_FPoint centre, const Sint32 p, 
                    const Uint32 phi_beg, const Uint32 phi_end); //Рисовка круга в полярных координатах
    static void DrawEllips(SDL_Renderer* renderer, const SDL_FPoint centre, const Sint32 a, 
                    const Sint32 b, const Uint32 phi_beg, const Uint32 phi_end);    
    static void DrawText(SDL_Renderer* renderer, TTF_Font* font, 
                    const char* string, const SDL_Rect where); //Рисовка текста
    static void DrawPart(SDL_Renderer* renderer, const ClassEngine::EnginePart* shape, 
                    const SDL_Point where); //Рисовка контура детали
    static void DrawPart(SDL_Renderer* renderer, const ClassEngine::EnginePart* shape); //Рисовка контура детали
    static void DrawTextureAngled(SDL_Renderer* renderer, const ClassEngine::EnginePart* shape,
                    SDL_Point where, float angle, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE); //Рисовка контура детали под углом
    static void DrawTextureAngled(SDL_Renderer* renderer, const ClassEngine::EnginePart* shape,
                    float angle, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE); //Рисовка контура детали под углом
    static void DrawTextureAngled(SDL_Renderer* renderer, const ClassEngine::EnginePart* shape,
                    SDL_Point where, SDL_Point* around, float angle, SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE); //Рисовка контура детали под углом
};

#endif //_CLASS_RENDERER_HPP_
