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
    
    SDL_RenderDrawLineF(this->renderer, 0, 325, 400, 325);
    SDL_RenderDrawLineF(this->renderer, 160 + 30, 0, 160 + 30, 400);

    SDL_RenderDrawLineF(this->renderer, 0, 290, 400, 290);
    //SDL_RenderDrawLineF(this->renderer, 0, 301, 400, 301);
    SDL_RenderDrawLineF(this->renderer, 160 + 30, 0, 160 + 30, 400);
    if (this->animation_on)
    {
        std::cout << this->en->GetPart(PN::CRANK)->angle << "\n";
        std::cout << this->en->GetPart(PN::LINK_ROD)->x << " " << this->en->GetPart(PN::LINK_ROD)->y << "\n";
    }


    SDL_RenderPresent(this->renderer);
}
