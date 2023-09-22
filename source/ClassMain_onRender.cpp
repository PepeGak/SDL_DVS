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
    SDL_RenderDrawLine(this->renderer, 245, 160, 350, 160);
    SDL_RenderDrawLine(this->renderer, 245, 214, 350, 214);
    ClassRenderer::DrawText(this->renderer, this->font, "ВМТ", 355, 150);
    ClassRenderer::DrawText(this->renderer, this->font, "НМТ", 355, 214);

    SDL_SetRenderDrawColor(this->renderer, 0b11111111, 255, 0xFF, SDL_ALPHA_OPAQUE);
    ClassRenderer::DrawText(this->renderer, this->font, "Модель двигателя:", 106, 45);

    std::vector<std::string> engine_info =
    {
        "Информация о двигателе:",
        "Тип: L4",
        "Размер рабочей камеры: 58x70 мм",
        "Объём двигателя: 740 см3",
        "Степень сжатия: 9:1",
        "Среднее эффективное давление: 520 кПа",
        "Топливо: АИ-95"
    };

    for (Sint32 i = 0; i < engine_info.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, engine_info[i].c_str(), 80, 440 + 25 * i);

    std::vector<std::string> strokes =
    {
        "Такт двигателя: " + std::to_string(this->en->GetStroke()),
        "Впуск",
        "Сжатие",
        "Рабочий ход",
        "Выпуск"
    };
    ClassRenderer::DrawText(this->renderer, this->font, strokes[0].c_str(), 330, 40);
    ClassRenderer::DrawText(this->renderer, this->font, this->en->GetStroke() == 0 ? "-" : strokes[this->en->GetStroke()].c_str(), 330, 60);


    float Torque = ClassMath::Calculate_T(
            ClassMath::Cm3_To_Litres(static_cast<float>(this->en->GetV_d())), 
            ClassMath::Pascal_To_Bar(this->en->GetP_me() * 10e6));
    float A = ClassMath::Calculate_A(this->en->GetRPM(), Torque);
    float Q = ClassMath::Calculate_Q(this->en->GetRPM(), 1481*10e-8, 33*10e6);
    float effeciency = ClassMath::Calculate_Effeciency(static_cast<Sint32>(A), static_cast<Sint32>(Q));
    if (std::isnan(effeciency))
        effeciency = 0;
    float W = ClassMath::Calculate_W(this->en->GetP_me(), this->en->GetV_d());
    float P = ClassMath::Calculate_P(W, this->en->GetRPM(), 2) * 10e-3;

    if (!this->kW)
        P = ClassMath::kW_To_HP(P);
    
    std::vector<std::string> engine_formulas =
    {
        "Количество оборотов в минуту: " + std::to_string(this->en->GetRPM()),
        "При этих оборотах:",
        "Момент силы: " + std::to_string(static_cast<Sint32>(Torque)) + " Н*м",
        "Потребляемая энергия: " + std::to_string(static_cast<Sint32>(Q)) + " Дж",
        "Полезная энергия: " + std::to_string(static_cast<Sint32>(A)) + " Дж",
        "КПД: " + std::to_string(effeciency * 100) + " %",
        "Работа за цикл: " + std::to_string(W) + " Дж",
        "Мощность: " + std::to_string(P) + (this->kW ? " кВт" : " л.с."),
    };

    for (Sint32 i = 0; i < engine_formulas.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, engine_formulas[i].c_str(), 620, 40 + 25 * i);

    std::vector<std::string> help_info =
    {
        "Помощь:",
        "Q - запустить/остановить анимацию",
        "↑/W - увеличить обороты",
        "↓/S - уменьшить обороты",
        "R - замена кВт на л.с. и обратно"
    };

    for (Sint32 i = 0; i < help_info.size(); i++)
        ClassRenderer::DrawText(this->renderer, this->font, help_info[i].c_str(), 620, 280 + 25 * i);

    SDL_RenderPresent(this->renderer);
}
