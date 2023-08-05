#include "ClassMain.hpp"

void ClassMain::onRender()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender()\n";
#endif //_DVS_DEBUG_

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer);

    using PN = ClassEngine::PartNames;

    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::ENGINE_BODY));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::PISTON));
    ClassRenderer::DrawTextureAngled(this->renderer, this->en->GetPart(PN::LINK_ROD),
                                     this->en->GetPart(PN::LINK_ROD)->angle, SDL_FLIP_NONE);
    ClassRenderer::DrawTextureAngled(this->renderer, this->en->GetPart(PN::CRANK),
                                     this->en->GetPart(PN::CRANK)->angle, SDL_FLIP_NONE);
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::VALVE_IN));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(PN::VALVE_OUT));
    if (this->en->GetStroke())
        ClassRenderer::DrawRect(this->renderer, this->fuel->GetWM(), this->fuel->GetWM_Color());

    SDL_SetRenderDrawColor(this->renderer, 255, 140, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(this->renderer, 245, 160, 420, 160);
    SDL_RenderDrawLine(this->renderer, 245, 238, 420, 238);
    ClassRenderer::DrawText(this->renderer, this->font, "ВМТ", 425, 150);
    ClassRenderer::DrawText(this->renderer, this->font, "НМТ", 425, 228);

    SDL_SetRenderDrawColor(this->renderer, 220, 220, 220, SDL_ALPHA_OPAQUE);
    ClassRenderer::DrawText(this->renderer, this->font, "Схема упрощённого ДВС", 75, 50);
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    ClassRenderer::DrawText(this->renderer, this->font, "Общая информация о двигателе:", 88, 460);

    const std::vector<std::string> info =
        {
            "Тип двигателя: L4",
            "Объём рабочей камеры: " + std::to_string(this->en->GetVh1()) + " см^3",
            "Степень сжатия: " + std::to_string(this->en->GetE()),
            "Среднее эффективное давление: " + std::to_string(this->en->GetPe()),
            "КПД: 60%"
        };
    for (Uint32 i = 0; i < info.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, info[i].c_str(), 88, 486 + 26 * i);

    ClassRenderer::DrawText(this->renderer, this->font, "Такт рабочего цикла:", 360, 50);
    const std::vector<std::string> stroke = {"Впуск", "Сжатие", "Рабочий ход", "Выпуск"};
    if (!this->en->GetStroke() && !this->animation_on)
        ClassRenderer::DrawText(this->renderer, this->font, "Анимация не запущена", 360, 76);
    else if (!this->animation_on)
    {
        auto t = stroke[this->en->GetStroke() - 1] + " (пауза)";
        ClassRenderer::DrawText(this->renderer, this->font, t.c_str(), 360, 76);
    }
    else
        ClassRenderer::DrawText(this->renderer, this->font, stroke[this->en->GetStroke() - 1].c_str(), 360, 76);

    std::string RPM_s = "Обороты в минуту: " + std::to_string(this->en->GetRPM());
    ClassRenderer::DrawText(this->renderer, this->font, RPM_s.c_str(), 640, 50);

    std::string P_s = "Вырабатываемая мощность: ";
    auto P = ClassMath::CalculateNe(this->en->GetVh1() * 4, this->en->GetPe(), this->en->GetRPM());
    if (!this->kW)
    {
        auto hp = ClassMath::kWToHP(P);
        P_s += std::to_string(hp) + " л.с.";
    }
    else
        P_s += std::to_string(P) + " кВт.";
    ClassRenderer::DrawText(this->renderer, this->font, P_s.c_str(), 640, 76);

    std::string A_s = "Полезная работа: ";
    if (this->animation_on)
    {
        auto A = static_cast<Sint32>(SDL_GetTicks() / 1000.0f * P);
        A_s += std::to_string(A) + " Дж.";
    }
    else
        A_s += "анимация не запущена";
    ClassRenderer::DrawText(this->renderer, this->font, A_s.c_str(), 640, 100);

    std::string Q_s = "Теплота сгорания топлива: ";
    if (this->animation_on)
    {
        auto Q = static_cast<Sint32>(SDL_GetTicks() / 1000.0f * P * 1.7f);
        Q_s += std::to_string(Q) + " Дж.";
    }
    else
        Q_s += "анимация";
    ClassRenderer::DrawText(this->renderer, this->font, Q_s.c_str(), 640, 125);
    if (!this->animation_on)
        ClassRenderer::DrawText(this->renderer, this->font, "не запущена", 640, 140);


    SDL_SetRenderDrawColor(this->renderer, 255, 160, 122, SDL_ALPHA_OPAQUE);
    const std::vector<std::string> help =
        {
            "Q - поставить на паузу",
            "Escape - выйти",
            "↑/W - увеличить количество оборотов",
            "↓/S - уменьшить количество оборотов",
            "R - сменить кВт на л.с. и обратно"};
    for (Uint32 i = 0; i < help.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, help[i].c_str(), 640, 190 + 26 * i);

    SDL_RenderPresent(this->renderer);
}
