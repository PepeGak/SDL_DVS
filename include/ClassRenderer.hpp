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
                    const char* string, const SDL_Rect& where); //Рисовка текста
    static void DrawPart(SDL_Renderer* renderer, const ClassEngine::EnginePart* shape); //Рисовка контура детали
};

#endif //_CLASS_RENDERER_HPP_
