#include "ClassMain.hpp"

void ClassMain::onRender()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onRender()\n";
#endif

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
    std::string help[] = 
    {
        "Q - завести/заглушить двигатель",
        ""
    };
}

void ClassMain::onRender_Screen()
{
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(0));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(1));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(2));
    ClassRenderer::DrawPart(this->renderer, this->en->GetPart(3));

    SDL_SetRenderDrawColor(this->renderer, 128, 128, 128, 30);
    int w, h; SDL_GetWindowSize(this->window, &w, &h);
    SDL_RenderDrawLineF(this->renderer, 
                    this->en->GetPart(0)->centre.x + 100 * 1.5f, 0,
                    this->en->GetPart(0)->centre.x + 100 * 1.5f, h - 400);

    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_Rect where = {50, 50, 0, 0};
    TTF_SizeUTF8(this->font, "Зажигания в цилиндрах", &where.w, &where.h);
    ClassRenderer::DrawText(this->renderer, this->font, "Зажигания в цилиндрах", where);
}
