/*
* Класс, отвечающий за характеристики топлива
*/
#ifndef _CLASS_FUEL_HPP_
#define _CLASS_FUEL_HPP_

class ClassFuel
{
public:
    /*
    * Октановое число топлива
    */
    enum class Octane_Rating
    {
        AI_92 = 0,
        AI_95,
        AI_98
    };

private:
    double fuel_ratio;
    Octane_Rating rating;
};

#endif //_CLASS_FUEL_HPP_
