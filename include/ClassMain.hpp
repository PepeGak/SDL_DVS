/*
* Класс, соединяющий все компоненты воедино, и отвечающий за основной цикл приложения
*/
#ifndef _CLASS_MAIN_HPP_
#define _CLASS_MAIN_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "ClassEvent.hpp"
#include "ClassEngine.hpp"
#include "ClassMath.hpp"
#include "ClassFuel.hpp"
#include "ClassMusic.hpp"
#include "ClassRenderer.hpp"

class ClassMain : private ClassEvent
{
public:
    ClassMain();
    ~ClassMain();

    int onExecute();
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

    bool onInit();
    void onEvent(SDL_Event* ev) override;
    void onRender();
    void onLoop();
    void onQuit();
    bool appRunning;

    void onExit() override;

    ClassEngine* en;
};

#endif //_CLASS_MAIN_HPP_
