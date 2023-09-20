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

        float alpha = this->en->GetPart(PN::CRANK)->angle - 90;
        this->en->SetPartX(PN::LINK_ROD, 167 + 35 * cosf(ClassMath::DegToRad(alpha)));
        this->en->SetPartY(PN::LINK_ROD, 200 + 35 * sinf(ClassMath::DegToRad(alpha)));

        const float max_angle = 6.0f;
        float cur_crank_angle = this->en->GetPart(PN::CRANK)->angle;
        if ((cur_crank_angle >= 0 && cur_crank_angle < 90) || (cur_crank_angle >= 270 && cur_crank_angle < 360))
            this->en->SetPartAngle(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->angle - max_angle / 90);
        else if (cur_crank_angle >= 90 && cur_crank_angle < 270)
            this->en->SetPartAngle(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->angle + max_angle / 90);
        
        if (cur_crank_angle >= 0 && cur_crank_angle < 180)
            this->en->SetPartY(PN::PISTON, this->en->GetPart(PN::PISTON)->y + 0.3f);
        else if (cur_crank_angle >= 180 && cur_crank_angle < 360)
            this->en->SetPartY(PN::PISTON, this->en->GetPart(PN::PISTON)->y - 0.3f);

        switch (this->en->GetStroke())
        {
        case 1:
            
            break;
        
        case 2:

            break;

        case 3:
        
            break;

        case 4:

            break;

        default:
            break;
        }

        if (cur_crank_angle == 1 && this->en->GetStroke() == 0)
            this->en->SetStroke(1);
        else if (cur_crank_angle == 0 || cur_crank_angle == 180 || cur_crank_angle == 360)
            this->en->SetStroke(this->en->GetStroke() + 1);
        if (this->en->GetStroke() > 4)
            this->en->SetStroke(1);
    }
}
