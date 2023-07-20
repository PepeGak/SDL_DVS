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
            "Escape - выйти"};
    for (Uint32 i = 0; i < help.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, help[i].c_str(), 50, 50 + 26 * i);
}

void ClassMain::onRender_Screen()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender_Screen()\n";
#endif //_DVS_DEBUG_

    using PN = ClassEngine::PartNames;

    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::ENGINE_BODY));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::PISTON));
    ClassRenderer::DrawTextureAngled(this->renderer, this->en->GetPart(PN::LINK_ROD),
                                     this->en->GetPart(PN::LINK_ROD)->angle, SDL_FLIP_NONE);
    ClassRenderer::DrawTextureAngled(this->renderer, this->en->GetPart(PN::CRANK),
                                     this->en->GetPart(PN::CRANK)->angle, SDL_FLIP_NONE);
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::VALVE_IN));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::VALVE_OUT));
    ClassRenderer::DrawRect(this->renderer, this->fuel->GetWM(), this->fuel->GetWM_Color());

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    ClassRenderer::DrawText(this->renderer, this->font, "Схема упрощённого ДВС", 75, 50);
    ClassRenderer::DrawText(this->renderer, this->font, "Информация о двигателе:", 98, 460);

    const std::vector<std::string> info =
    {
        "Тип двигателя: L4",
        "Объём рабочей камеры: " + std::to_string(this->en->GetVh1()) + " см^3",
        "Степень сжатия: " + std::to_string(this->en->GetE())
    };
    for (Uint32 i = 0; i < info.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, info[i].c_str(), 98, 486 + 26 * i);
    
    ClassRenderer::DrawText(this->renderer, this->font, "Такт рабочего цикла:", 360, 50);
    const std::vector<std::string> stroke =
    {
        "Впуск",
        "Сжатие",
        "Рабочий ход (расширение)",
        "Выпуск"
    };
    ClassRenderer::DrawText(this->renderer, this->font, stroke[this->en->GetStroke() - 1].c_str(), 360, 76);

    

}
