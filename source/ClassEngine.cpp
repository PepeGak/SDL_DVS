#include "ClassEngine.hpp"

ClassEngine::ClassEngine(SDL_Renderer *renderer)
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEngine::ClassEngine(EngineType, SDL_Renderer*)\n";
#endif
    this->fuel_ratio = 0;
    this->filling_ratio = 0;
    this->RPM = 0;
    this->efficiency = 0;
    this->stroke = 0;
    this->renderer = renderer;

    // Внешний каркас, Поршень, Коленвал, Шатун, 2 Клапана
    this->engineParts.reserve(6);
    this->engineParts = 
    {
        ClassEngine::EnginePart(),
        ClassEngine::EnginePart(),
        ClassEngine::EnginePart(),
        ClassEngine::EnginePart(),
        ClassEngine::EnginePart(),
        ClassEngine::EnginePart()
    };
    this->LoadShape("./assets/engine_assets/engine_body.png", 0);
    this->LoadShape("./assets/engine_assets/piston.png", 1);
    this->LoadShape("./assets/engine_assets/crank.png", 2);
    this->LoadShape("./assets/engine_assets/link_rod.png", 3);
}

ClassEngine::~ClassEngine()
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEngine::~ClassEngine()\n";
#endif

    for (auto &i : this->engineParts)
    {
        if (i.texture)
            SDL_DestroyTexture(i.texture);
        i.texture = nullptr;
    }
    this->engineParts.clear();
}

void ClassEngine::SetPartAngle(const PartNames index, float angle)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassEngine::SetPartAngle(const PartNames, float)\n";
#endif

    while (angle > 360)
        angle -= 360.0f;
    this->engineParts[static_cast<Uint32>(index)].angle = angle;
}

void ClassEngine::LoadShape(const char *path, const Sint32 index)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassEngine::LoadShape(const char*)\n";
#endif

    if (!path)
        return;
    
    SDL_Surface *surface = nullptr;
    surface = IMG_Load(path);
    if (!surface)
    {
        std::cout << SDL_GetError() << "\n";
        return;
    }
    
    if(SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 0)) < 0)
    {
        SDL_FreeSurface(surface); surface = nullptr;
        std::cout << SDL_GetError() << "\n";
        return;
    }
    
    this->engineParts[index].texture = SDL_CreateTextureFromSurface(this->renderer, surface);
    if (!this->engineParts[index].texture)
    {
        SDL_FreeSurface(surface); surface = nullptr;
        std::cout << SDL_GetError() << "\n";
        return;
    }

    SDL_FreeSurface(surface); surface = nullptr;
}
