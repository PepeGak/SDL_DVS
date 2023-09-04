#include "ClassMain.hpp"

void ClassMain::onRender()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender()\n";
#endif //_DVS_DEBUG_

    using PN = ClassEngine::PartNames;

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer);

    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::LINK_ROD));
    ClassRenderer::DrawPartAngled(this->renderer, this->en->GetPart(PN::CRANK), this->en->GetPart(PN::CRANK)->angle);
    
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 0);
    
    SDL_RenderDrawLineF(this->renderer, 0, 280 + 45, 400, 280 + 45);
    SDL_RenderDrawLineF(this->renderer, 160 + 30, 0, 160 + 30, 400);

    SDL_RenderDrawLineF(this->renderer, 0, 235 + 45, 400, 235 + 45);
    SDL_RenderDrawLineF(this->renderer, 160 + 30, 0, 160 + 30, 400);


    SDL_RenderPresent(this->renderer);
}
