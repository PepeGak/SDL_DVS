/*
* Класс, соединяющий все компоненты воедино, и отвечающий за основной цикл приложения
*/
#ifndef _CLASS_MAIN_HPP_
#define _CLASS_MAIN_HPP_

#include "ClassEvent.hpp"

class ClassMain : private ClassEvent
{
public:
    ClassMain();
    ~ClassMain();

    int onExecute();
    
private:
    bool onInit();
    void onEvent(SDL_Event* ev) override;
    void onRender();
    void onLoop();
    void onQuit();
    bool appRunning;

};

#endif //_CLASS_MAIN_HPP_
