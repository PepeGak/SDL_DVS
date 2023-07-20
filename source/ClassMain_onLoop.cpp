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
        {
            speed = 5;
            this->en->SetStroke(this->en->GetStroke() + 1);
        }
        if ((this->en->GetPart(PN::PISTON)->y >= this->en->GetPart(PN::ENGINE_BODY)->y + 140) && speed > 0)
        {
            speed = -5;
            this->en->SetStroke(this->en->GetStroke() + 1);
        }

        if ((en->GetPart(PN::CRANK)->angle >= 0 && en->GetPart(PN::CRANK)->angle < 90) ||
            (en->GetPart(PN::CRANK)->angle >= 270 && en->GetPart(PN::CRANK)->angle < 360))
            this->en->SetPartAngle(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->angle + 2.5f);
        if ((en->GetPart(PN::CRANK)->angle >= 90 && en->GetPart(PN::CRANK)->angle < 270))
            this->en->SetPartAngle(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->angle - 2.5f);

        switch (this->en->GetStroke())
        {
        case 1:
        case 2:
            this->fuel->SetWM_Color({ 0x00, 0x80, 0xFF });
            break;

        case 3:
            this->fuel->SetWM_Color({ 0xFF, 0x80, 0x00 });
            break;

        case 4:
            this->fuel->SetWM_Color({ 0x96, 0x96, 0x96 });
            break;
        
        default:
            this->en->SetStroke(this->en->GetStroke() % 4);
            break;
        }
        
        std::cout << this->en->GetStroke() << "\n";

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
