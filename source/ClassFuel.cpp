#include "ClassFuel.hpp"

ClassFuel::ClassFuel()
{
    this->working_mixture = { 0, 0, 0, 0 };
    this->wm_color = { 0x00, 0x80, 0xFF };
}

ClassFuel::ClassFuel(Sint32 x, Sint32 y)
{
    this->working_mixture = { static_cast<float>(x), static_cast<float>(y), 0, 0 };
    this->wm_color = { 0x00, 0x80, 0xFF };
}

ClassFuel::~ClassFuel()
{
}
