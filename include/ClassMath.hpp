/*
* Класс, отвечающий за различные формулы, связанные с работой двигателя и топливом
*/
#ifndef _CLASS_MATH_HPP_
#define _CLASS_MATH_HPP_

#include <cmath>

#include <ClassEngine.hpp>
#include <ClassFuel.hpp>

class ClassMath
{
public:

    ClassMath();
    ~ClassMath();
    
    inline static Sint32 kWToHP(float kW) { return static_cast<Sint32>(kW * 1.35f); }
    inline static float HPtokW(float HP) { return HP * 0.735f; }
    static Sint32 CalculateNe(Uint32 Vh, float pe, Uint32 RPM);
    inline static float CalculateEffeciency(float A, float Q) { return A / Q; }
    static float DegToRad(float degrees);
    static float RadToDeg(float radians);

private:

    

};

#endif
