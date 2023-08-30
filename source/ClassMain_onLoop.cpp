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

        if (this->en->GetPart(PN::CRANK)->angle >= 0 && this->en->GetPart(PN::CRANK)->angle < 180)
            this->en->SetPartY(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->y - 1);
        else if (this->en->GetPart(PN::CRANK)->angle >= 180 && this->en->GetPart(PN::CRANK)->angle < 360)
            this->en->SetPartY(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->y + 1);

    }
    
}
