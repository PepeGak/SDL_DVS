/*
* Класс, отвечающий за различные формулы, связанные с работой двигателя и топливом
*/
#ifndef _CLASS_MATH_HPP_
#define _CLASS_MATH_HPP_

#include <cmath>

#include "ClassEngine.hpp"
#include "ClassFuel.hpp"

class ClassMath final
{
public:

    ClassMath() {};
    ~ClassMath() {};
    
    inline static Sint32 kW_To_HP(float kW) { return static_cast<Sint32>(kW * 1.35f); }
    inline static float HP_to_kW(float HP) { return HP * 0.735f; }
    inline static float Deg_To_Rad(float degrees) { return degrees * M_PI / 180; }
    inline static float Rad_To_Deg(float radians) { return radians * 180 / M_PI; }
    inline static float Pascal_To_Bar(float pascal) { return pascal / 100000; }
    inline static float Bar_To_Pascal(float bar) { return bar * 100000; }
    inline static float Cm3_To_Litres(float V) { return V / 1000; };
    inline static float Litres_To_Cm3(float L) { return L * 1000; };

    static float Calculate_A(Sint32 N, float T);
    static float Calculate_Q(Sint32 N, float R, float Q_b);
    inline static float Calculate_Effeciency(float A, float Q) { return A / Q; }
    static float Calculate_W(float p_me, float V_d);
    static float Calculate_P(float W, Sint32 N, Sint32 n_c);
    static float Calculate_T(float V_d, float p_me);

private:

    

};

#endif
