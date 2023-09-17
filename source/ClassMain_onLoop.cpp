#include "ClassMain.hpp"

void ClassMain::onLoop()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onLoop()\n";
#endif

    if (this->animation_on)
    {
        using PN = ClassEngine::PartNames;
        this->en->SetPartAngle(PN::CRANK, this->en->GetPart(PN::CRANK)->angle + 1);
        
        this->en->SetPartX(PN::LINK_ROD, 167 + 35 * cosf(ClassMath::DegToRad(this->en->GetPart(PN::CRANK)->angle)));
        this->en->SetPartY(PN::LINK_ROD, 167 + 35 * sinf(ClassMath::DegToRad(this->en->GetPart(PN::CRANK)->angle)));
        
    }
    
}
