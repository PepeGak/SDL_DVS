/*
* Класс, отвечающий за характеристики топлива
*/
#ifndef _CLASS_FUEL_HPP_
#define _CLASS_FUEL_HPP_

#include <SDL2/SDL.h>

class ClassFuel
{
public:
    /*
    * Октановое число топлива
    */
    enum class Octane_Rating
    {
        AI_92 = 0,
        AI_95,
        AI_98
    };

    ClassFuel();
    ClassFuel(Sint32 x, Sint32 y);
    ~ClassFuel();

    inline void SetWM_Color(SDL_Color color) { this->wm_color = color; }
    inline void SetWM_w(Sint32 w) { this->working_mixture.w = w; }
    inline void SetWM_h(Sint32 h) { this->working_mixture.h = h; }
    inline SDL_Color GetWM_Color() { return this->wm_color; }
    inline SDL_Rect GetWM() { return this->working_mixture; }

protected:
    Octane_Rating rating; //Октановое число
    SDL_Rect working_mixture; //Рабочая смесь
    SDL_Color wm_color; //Цвет рабочей смеси
};

#endif //_CLASS_FUEL_HPP_
