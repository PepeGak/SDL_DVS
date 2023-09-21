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
        ClassRenderer::DrawRect(this->renderer, this->fuel->GetWM(), this->fuel->GetWM_Color());

    SDL_SetRenderDrawColor(this->renderer, 255, 140, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(this->renderer, 245, 160, 420, 160);
    SDL_RenderDrawLine(this->renderer, 245, 214, 420, 214);
    ClassRenderer::DrawText(this->renderer, this->font, "ВМТ", 425, 150);
    ClassRenderer::DrawText(this->renderer, this->font, "НМТ", 425, 214);

    SDL_RenderPresent(this->renderer);
}
