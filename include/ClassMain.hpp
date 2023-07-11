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

#define _DVS_DEBUG_
#undef _DVS_DEBUG_

class ClassMain : private ClassEvent
{
public:
    ClassMain();
    ~ClassMain();

    int onExecute();
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;

    bool onInit();
    void onEvent(SDL_Event* ev) override;
    void onRender();
    void onRender_Help();
    void onRender_Screen();
    void onLoop();
    void onQuit();
    bool appRunning;

    void onExit() override;
    void onKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode) override;
    void onKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode) override;
    void onLMouseDown(Sint32 xm, Sint32 ym) override;

    ClassEngine* en;
    ClassMusic* mus;
    
    Uint32 FPS;
    Uint32 frameDelay;
    Uint32 frameStart, frameTime;
    
    enum class MenuList
    {
        HELP_TEXT = 0,
        ENGINE_SCREEN
    } menu_options;
};

#endif //_CLASS_MAIN_HPP_
