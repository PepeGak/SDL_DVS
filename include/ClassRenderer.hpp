/*
* Класс, отвечающий за отрисовку различных фигур, текстур и текста
*/
#ifndef _CLASS_RENDERER_HPP_
#define _CLASS_RENDERER_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class ClassRenderer
{
public:
    static void Draw(SDL_Renderer* renderer, SDL_Point points[], Sint32 amount); //Рисовка линий по нескольким точкам
    static void Draw(SDL_Renderer* renderer, SDL_Point centre, Sint32 p, 
        Uint32 phi, Uint32 phi_beg = 0); //Рисовка круга в полярных координатах
    static void Draw(SDL_Renderer* renderer, TTF_Font* font, 
        const char* string, SDL_Rect where, SDL_Colour colour); //Рисовка текста
};

#endif //_CLASS_RENDERER_HPP_
