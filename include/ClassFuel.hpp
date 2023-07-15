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

protected:
    Octane_Rating rating; //Октановое число
};

#endif //_CLASS_FUEL_HPP_
