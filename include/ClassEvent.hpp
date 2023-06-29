/*
* Для обработки различных событий: нажатие клавиш и тд.
*/
#ifndef _CLASS_EVENT_HPP_
#define _CLASS_EVENT_HPP_

#include <SDL2/SDL.h>

class ClassEvent
{
public:
    ClassEvent();
    ~ClassEvent();
    virtual void onEvent(SDL_Event* ev);
};

#endif //_CLASS_EVENT_HPP_
