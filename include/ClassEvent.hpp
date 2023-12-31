/*
 * Класс для обработки различных событий: нажатие клавиш и тд.
 */
#ifndef _CLASS_EVENT_HPP_
#define _CLASS_EVENT_HPP_

#include <SDL2/SDL.h>

class ClassEvent
{
public:
    ClassEvent();
    virtual ~ClassEvent();
    virtual void onEvent(SDL_Event *ev);
    virtual void onExit() = 0;
    virtual void onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
    virtual void onKeyHDown() = 0;
    virtual void onKeyQDown() = 0;
    virtual void onKeyRDown() = 0;
    virtual void onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
    virtual void onLMouseDown(Sint32 xm, Sint32 ym) = 0;
    virtual void onArrowUpDown() = 0;
    virtual void onArrowDownDown() = 0;
};

#endif //_CLASS_EVENT_HPP_
