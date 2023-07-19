#include "ClassMain.hpp"

void ClassMain::onRender()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender()\n";
#endif //_DVS_DEBUG_

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer);
    
    switch (this->menu_options)
    {
    case ClassMain::MenuList::ENGINE_SCREEN:
        this->onRender_Screen();
        break;

    case ClassMain::MenuList::HELP_TEXT:
        this->onRender_Help();
        break;
    }

    SDL_RenderPresent(this->renderer);
}

void ClassMain::onRender_Help()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender_Help()\n";
#endif //_DVS_DEBUG_

    std::string help[] = 
    {
        "Q - завести/заглушить двигатель",
        "Escape - выйти"
    };
    for (Sint32 i = 0; i < sizeof(help) / sizeof(std::string); i++)
    {
        SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_Rect where = {50, 50 + 20 * i, 0, 0};
        TTF_SizeUTF8(this->font, help[i].c_str(), &where.w, &where.h);
        ClassRenderer::DrawText(this->renderer, this->font, help[i].c_str(), where);
    }
}

void ClassMain::onRender_Screen()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender_Screen()\n";
#endif //_DVS_DEBUG_

    typedef ClassEngine::PartNames PN;

    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::ENGINE_BODY));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::PISTON));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::LINK_ROD));

    ClassRenderer::DrawTextureAngled(this->renderer, this->en->GetPart(PN::LINK_ROD),
                    this->en->GetPart(PN::LINK_ROD)->angle, SDL_FLIP_NONE);

    ClassRenderer::DrawTextureAngled(this->renderer, this->en->GetPart(PN::CRANK),
                    this->en->GetPart(PN::CRANK)->angle, SDL_FLIP_NONE);

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_Rect where = {50, 50, 0, 0};
    TTF_SizeUTF8(this->font, "Зажигания в цилиндрах", &where.w, &where.h);
    ClassRenderer::DrawText(this->renderer, this->font, "Зажигания в цилиндрах", where);
}
