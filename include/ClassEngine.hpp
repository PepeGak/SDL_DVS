/*
* Класс, отвечающий за различные харакетристики двигателя: форма, кол-во оборотов в минуту,
* потребление горючего и тд.
*/
#ifndef _CLASS_ENGINE_HPP_
#define _CLASS_ENGINE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fstream>
#include <iostream>
#include <vector>

class ClassEngine
{
public:

    enum class PartNames
    {
        ENGINE_BODY = 0, //Каркас двигателя
        PISTON, //Поршень
        CRANK, //Коленвал
        LINK_ROD, //Шатун
        VALVE //Клапан
    };

    /*
    * Структура, описываюшая различные запчасти двигателя
    */
    struct EnginePart
    {
    public:
        EnginePart() : texture(nullptr), x(0), y(0), angle(0.0f) {}
        ~EnginePart() {};

        SDL_Texture* texture;
        Sint32 x;
        Sint32 y;
        float angle;
    };

    ClassEngine(SDL_Renderer* renderer);
    ~ClassEngine();

    inline const EnginePart* GetPart(PartNames index) { return &this->engineParts[static_cast<Uint32>(index)]; }
    inline void SetPartX(const PartNames index, const Sint32 x) { this->engineParts[static_cast<Uint32>(index)].x = x; }
    inline void SetPartY(const PartNames index, const Sint32 y) { this->engineParts[static_cast<Uint32>(index)].y = y; }
    void SetPartAngle(const PartNames index, float angle);
    inline const auto& GetParts() { return this->engineParts; }
    
    
    Uint32 stroke; //такт двигателя

private:

    SDL_Renderer* renderer;
    std::vector<ClassEngine::EnginePart> engineParts;
    void LoadShape(const char* path, const Sint32 index);

protected:
    float fuel_ratio; //Коэф. избытка воздуха
    float filling_ratio; //Коэффициент наполнения
    Uint32 RPM; //Кол-во оборотов в минуту
    float efficiency; //КПД
};

#endif //_CLASS_ENGINE_HPP_
