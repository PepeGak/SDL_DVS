/*
* Класс, отвечающий за различные харакетристики двигателя: форма, кол-во оборотов в минуту,
* потребление горючего и тд.
*/
#ifndef _CLASS_ENGINE_HPP_
#define _CLASS_ENGINE_HPP_

#include <SDL2/SDL.h>
#include <fstream>
#include <iostream>
#include <vector>

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

    /*
    * Структура, описываюшая различные запчасти двигателя
    */
    struct EnginePart
    {
    public:
        EnginePart() : shape(nullptr), pointAmount(0) {}
        ~EnginePart() {};

        SDL_FPoint* shape;
        Sint32 pointAmount;
    };

    ClassEngine(EngineType type);
    ClassEngine(const char* path);
    ~ClassEngine();

    inline const EnginePart* GetPart(Sint32 index = 0) { return &this->engineParts[index]; }
    void Normalise(const double x, const double y, const Sint32 index);
    void NormaliseX(const double x, const Sint32 index);
    void NormaliseY(const double y, const Sint32 index);
    void Scale(const double k, const Sint32 index);

private:

    std::vector<ClassEngine::EnginePart> engineParts;
    void LoadShape(const char* path, const Sint32 index = 0);
    

protected:

};

#endif //_CLASS_ENGINE_HPP_
