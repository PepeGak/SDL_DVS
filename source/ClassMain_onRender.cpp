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
    std::string help_text = "1";
    int w, h;
    TTF_SizeUTF8(this->font, help_text.c_str(), &w, &h);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    ClassRenderer::Draw(this->renderer, this->font, help_text.c_str(), {100, 100, w, h});
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    ClassRenderer::Draw(this->renderer, {320, 240}, 20, 0, 300);
}

void ClassMain::onRender_Screen()
{
    SDL_Point some_points[10] =
        {
            {10, 10},
            {10, 15},
            {15, 50},
            {50, 60},
            {90, 20},
            {80, 50},
            {50, 240},
            {500, 40},
            {40, 470},
            {10, 10}};

    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    ClassRenderer::Draw(this->renderer, some_points, 10);

    SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
    ClassRenderer::Draw(this->renderer, this->en->GetPart(0));
    ClassRenderer::Draw(this->renderer, this->en->GetPart(1));

    SDL_SetRenderDrawColor(this->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

    SDL_Rect where = {50, 50, 32, 16};
    ClassRenderer::Draw(this->renderer, this->font, "Hi!", where);
}
