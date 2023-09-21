#include "ClassMain.hpp"

void ClassMain::onRender()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender()\n";
#endif //_DVS_DEBUG_

    using PN = ClassEngine::PartNames;

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer);

    ClassRenderer::DrawPartAngled(this->renderer, this->en->GetPart(PN::LINK_ROD), this->en->GetPart(PN::LINK_ROD)->angle);
    ClassRenderer::DrawPartAngled(this->renderer, this->en->GetPart(PN::CRANK), this->en->GetPart(PN::CRANK)->angle);
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::ENGINE_BODY));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::PISTON));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::VALVE_IN));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::VALVE_OUT));
    if (this->en->GetStroke())
        ClassRenderer::DrawRectF(this->renderer, this->fuel->GetWM(), this->fuel->GetWM_Color());

    SDL_SetRenderDrawColor(this->renderer, 255, 140, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(this->renderer, 245, 160, 420, 160);
    SDL_RenderDrawLine(this->renderer, 245, 214, 420, 214);
    ClassRenderer::DrawText(this->renderer, this->font, "ВМТ", 425, 150);
    ClassRenderer::DrawText(this->renderer, this->font, "НМТ", 425, 214);

    SDL_SetRenderDrawColor(this->renderer, 0b11111111, 255, 0xFF, SDL_ALPHA_OPAQUE);
    ClassRenderer::DrawText(this->renderer, this->font, "Модель двигателя", 106, 45);
    ClassRenderer::DrawText(this->renderer, this->font, "Информация о двигателе:", 80, 440);
    ClassRenderer::DrawText(this->renderer, this->font, "Тип: L4", 80, 460);
    ClassRenderer::DrawText(this->renderer, this->font, "Размер рабочей камеры: 58x70 мм", 80, 480);
    ClassRenderer::DrawText(this->renderer, this->font, "Объём двигателя: 740 см3", 80, 500);
    ClassRenderer::DrawText(this->renderer, this->font, "Степень сжатия: 9:1", 80, 520);


    SDL_RenderPresent(this->renderer);
}
