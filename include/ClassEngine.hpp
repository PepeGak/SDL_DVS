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

    /*
    * Индекс каждой детали
    */
    enum class PartNames
    {
        ENGINE_BODY = 0, //Каркас двигателя
        PISTON, //Поршень
        CRANK, //Коленвал 
        LINK_ROD, //Шатун
        VALVE_IN, //Впускной клапан
        VALVE_OUT //Выпускной клапан
    };

    /*
    * Структура, описываюшая различные запчасти двигателя
    */
    struct EnginePart
    {
    public:
        EnginePart() : texture(nullptr), x(0.0f), y(0.0f), angle(0.0f) {}
        ~EnginePart() {};

        SDL_Texture* texture;
        float x;
        float y;
        float angle;
    };

    ClassEngine(SDL_Renderer* renderer);
    ~ClassEngine();

    inline const EnginePart* GetPart(PartNames index) { return &this->engineParts[static_cast<Uint32>(index)]; }
    inline void SetPartX(const PartNames index, const float x) { this->engineParts[static_cast<Uint32>(index)].x = x; }
    inline void SetPartY(const PartNames index, const float y) { this->engineParts[static_cast<Uint32>(index)].y = y; }
    void SetPartAngle(const PartNames index, float angle);

    inline void SetRPM(const Sint32 RPM) { this->RPM = RPM; }
    inline void SetStroke(Uint32 stroke) { this->stroke = stroke; }
    inline Sint32 GetRPM() { return this->RPM; }
    inline Uint32 GetStroke() { return this->stroke; }
    inline Uint32 GetV_d() { return this->V_d; }
    inline float GetP_me() { return this->p_me; }

private:

    SDL_Renderer* renderer;
    std::vector<ClassEngine::EnginePart> engineParts;
    void LoadShape(const char* path, const Sint32 index);

protected:

    Uint32 E; //Степень сжатия
    Sint32 RPM; //Кол-во оборотов в минуту
    Uint32 stroke; //такт двигателя
    float p_me; //Среднее эффективное давление, МПа
    Uint32 V_d; //Объём двигателя, см^3
    Uint32 n; //Кол-во цилиндров
    float efficiency; //КПД

};

#endif //_CLASS_ENGINE_HPP_
