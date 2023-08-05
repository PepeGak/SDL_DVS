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
