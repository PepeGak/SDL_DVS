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

        std::cout << this->en->GetPart(PN::CRANK)->angle / 3 << "\n";

        if (this->en->GetPart(PN::CRANK)->angle >= 0 && this->en->GetPart(PN::CRANK)->angle < 180)
            this->en->SetPartY(PN::LINK_ROD, 167 + this->en->GetPart(PN::CRANK)->angle / 3);
        else if (this->en->GetPart(PN::CRANK)->angle >= 180 && this->en->GetPart(PN::CRANK)->angle < 360)
            this->en->SetPartY(PN::LINK_ROD, 167 + 120 - this->en->GetPart(PN::CRANK)->angle / 3);

    }
    
}
