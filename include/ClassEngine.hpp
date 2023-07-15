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
        EnginePart() : shape(nullptr), pointAmount(0), centre({0, 0}) {}
        ~EnginePart() {};

        SDL_FPoint* shape;
        Sint32 pointAmount;
        SDL_FPoint centre;
    };

    ClassEngine(EngineType type);
    ClassEngine(const char* path);
    ~ClassEngine();

    inline const EnginePart* GetPart(const Sint32 index) { return &this->engineParts[index]; }
    float GetPartWidth(const Sint32 index);
    float GetPartHeight(const Sint32 index);
    void Normalise(const float x, const float y, const Sint32 index);
    void NormaliseX(const float x, const Sint32 index);
    void NormaliseY(const float y, const Sint32 index);
    void Scale(const float k, const Sint32 index);
    void Scale(const float k);

private:

    std::vector<ClassEngine::EnginePart> engineParts;
    void LoadShape(const char* path, const Sint32 index);

protected:
    float fuel_ratio; //Коэф. избытка воздуха
    float filling_ratio; //Коэффициент наполнения
    Uint32 RPM; //Кол-во оборотов в минуту
    float efficiency; //КПД
    Uint32 stroke; //такт двигателя
};

#endif //_CLASS_ENGINE_HPP_
