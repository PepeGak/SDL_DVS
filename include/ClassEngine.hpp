/*
* Класс, отвечающий за различные харакетристики двигателя: форма, кол-во оборотов в минуту,
* потребление горючего и тд.
*/
#ifndef _CLASS_ENGINE_HPP_
#define _CLASS_ENGINE_HPP_

#include <SDL2/SDL.h>
#include <fstream>
#include <iostream>

class ClassEngine
{
public:
    /*
    * Вид двигателя
    */
    enum class EngineType
    {
	    R4 = 0,
	    V8
    };

    ClassEngine(EngineType type);
    ~ClassEngine();

private:

    SDL_Point* shape;
    Sint32 points_amount;
    void LoadShape(const char* path);
    

protected:

};

#endif //_CLASS_ENGINE_HPP_
