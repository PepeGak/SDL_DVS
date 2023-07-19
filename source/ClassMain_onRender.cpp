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

    
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    std::vector<std::string> help = 
    {
        "Q - завести/заглушить двигатель",
        "Escape - выйти"
    };
    for (Uint32 i = 0; i < help.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, help[i].c_str(), 50, 50 + 26 * i);
}

void ClassMain::onRender_Screen()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender_Screen()\n";
#endif //_DVS_DEBUG_

    typedef ClassEngine::PartNames PN;

    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::ENGINE_BODY));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::PISTON));
    ClassRenderer::DrawTextureAngled(this->renderer, this->en->GetPart(PN::LINK_ROD),
                    this->en->GetPart(PN::LINK_ROD)->angle, SDL_FLIP_NONE);
    ClassRenderer::DrawTextureAngled(this->renderer, this->en->GetPart(PN::CRANK),
                    this->en->GetPart(PN::CRANK)->angle, SDL_FLIP_NONE);

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    ClassRenderer::DrawText(this->renderer, this->font, "Схема упрощённого ДВС", 75u, 50u);
    ClassRenderer::DrawText(this->renderer, this->font, "Информация о двигателе:", 98, 460);

    std::vector<std::string> info = 
    {
        "Тип двигателя: L4",
        "Объём рабочей камеры: 0,8л.",
    };
    for (Uint32 i = 0; i < info.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, info[i].c_str(), 98, 486 + 26 * i);
        
}
