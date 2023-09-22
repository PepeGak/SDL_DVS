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
        this->en->SetPartX(PN::LINK_ROD, 167 + 35 * cosf(ClassMath::Deg_To_Rad(alpha)));
        this->en->SetPartY(PN::LINK_ROD, 200 + 35 * sinf(ClassMath::Deg_To_Rad(alpha)));

        const float max_angle = 6.0f;
        float cur_crank_angle = this->en->GetPart(PN::CRANK)->angle;
        if ((cur_crank_angle >= 0 && cur_crank_angle < 90) || (cur_crank_angle >= 270 && cur_crank_angle < 360))
            this->en->SetPartAngle(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->angle - max_angle / 90);
        else if (cur_crank_angle >= 90 && cur_crank_angle < 270)
            this->en->SetPartAngle(PN::LINK_ROD, this->en->GetPart(PN::LINK_ROD)->angle + max_angle / 90);
        
        float delta_s = 0.3f;
        if (cur_crank_angle >= 0 && cur_crank_angle < 180)
            delta_s = 0.3f;
        else if (cur_crank_angle >= 180 && cur_crank_angle < 360)
            delta_s = -0.3f;

        this->en->SetPartY(PN::PISTON, this->en->GetPart(PN::PISTON)->y + delta_s);
        this->fuel->SetWM_h(this->fuel->GetWM().h + delta_s);

        switch (this->en->GetStroke())
        {
        case 1:
            this->en->SetPartY(PN::VALVE_OUT, 78);
            this->en->SetPartY(PN::VALVE_IN, 80);
            this->fuel->SetWM_Color({0x00, 0x80, 0xFF});
            break;

        case 2:
            this->fuel->SetWM_Color({0x00, 0x80, 0xFF});
            this->en->SetPartY(PN::VALVE_IN, 78);
            break;

        case 3:
            this->fuel->SetWM_Color({0xFF, 0x80, 0x00});
            break;

        case 4:
            this->fuel->SetWM_Color({0x96, 0x96, 0x96});
            this->en->SetPartY(PN::VALVE_OUT, 80);
            break;

        default:
            this->en->SetStroke(this->en->GetStroke() % 4);
            break;
        }

        if (cur_crank_angle == 1 && this->en->GetStroke() == 0)
            this->en->SetStroke(1);
        else if (cur_crank_angle == 0 || cur_crank_angle == 180 || cur_crank_angle == 360)
            this->en->SetStroke(this->en->GetStroke() + 1);
    }
}
