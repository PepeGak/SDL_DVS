#include "ClassMain.hpp"

void ClassMain::onLoop()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onLoop()\n";
#endif

    static float speed = -5;

    switch (this->menu_options)
    {
    case ClassMain::MenuList::ENGINE_SCREEN:
        
        using PN = ClassEngine::PartNames;

        if ((this->en->GetPart(PN::PISTON)->y <= this->en->GetPart(PN::ENGINE_BODY)->y + 60) && speed < 0)
            speed = 5;
        if ((this->en->GetPart(PN::PISTON)->y >= this->en->GetPart(PN::ENGINE_BODY)->y + 140) && speed > 0)
            speed = -5;

        this->en->SetPartAngle(PN::CRANK, this->en->GetPart(PN::CRANK)->angle + 11.5f);
        this->en->SetPartY(PN::PISTON, this->en->GetPart(PN::PISTON)->y + speed);
        this->en->SetPartY(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->y + speed);
        break;

    case ClassMain::MenuList::HELP_TEXT:
        break;

    default:
        break;
    }
}
