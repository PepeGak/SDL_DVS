#include "ClassMath.hpp"

ClassMath::ClassMath()
{
}

ClassMath::~ClassMath()
{
}

Sint32 ClassMath::CalculateNe(Uint32 Vh, float pe, Uint32 RPM)
{
    Sint32 Ne = Vh * RPM * pe / 120;
    return Ne;
}

float ClassMath::DegToRad(float degrees)
{
    float rad = degrees * M_PI / 180;
    return rad;
}

float ClassMath::RadToDeg(float radians)
{
    float deg = radians * 180 / M_PI;
    return deg;
}
