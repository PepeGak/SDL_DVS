#include "ClassEngine.hpp"

ClassEngine::ClassEngine(EngineType type)
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEngine::ClassEngine(EngineType)\n";
#endif

    switch (type)
    {
    case EngineType::R4:
        //Внешний каркас, Поршень, Верх, Коленвал, Шатун, 2 Клапана
        this->engineParts.reserve(7);
        this->engineParts = 
        {
            ClassEngine::EnginePart(),
            ClassEngine::EnginePart(),
            ClassEngine::EnginePart(),
            ClassEngine::EnginePart(),
            ClassEngine::EnginePart(),
            ClassEngine::EnginePart(),
            ClassEngine::EnginePart()
        };
        this->LoadShape("./assets/engine_assets/R4/engine_body.dat", 0);
        this->LoadShape("./assets/engine_assets/R4/piston.dat", 1);
        this->LoadShape("./assets/engine_assets/R4/engine_head.dat", 2);
        this->LoadShape("./assets/engine_assets/R4/crank.dat", 3);
        this->LoadShape("./assets/engine_assets/R4/link_rod.dat", 4);
        break;

    case EngineType::V8:
        break;

    default:
        break;
    }
}

ClassEngine::ClassEngine(const char *path)
{
    this->engineParts.push_back(ClassEngine::EnginePart());
    this->LoadShape(path, 0);
}

ClassEngine::~ClassEngine()
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEngine::~ClassEngine()\n";
#endif

    for (auto& i : this->engineParts)
    {
        if (i.texture)
            SDL_DestroyTexture(i.texture);
        i.centre = {0, 0};
        i.shape_rect = {0, 0, 0, 0};
        i.texture = nullptr;
    }
    this->engineParts.clear();
    
}

void ClassEngine::Normalise(const float x, const float y, const Sint32 index)
{
    
}

void ClassEngine::NormaliseY(const float y, const Sint32 index)
{
    
}

void ClassEngine::Scale(const float k, const Sint32 index)
{
    
}

void ClassEngine::Scale(const float k)
{
    
}

void ClassEngine::NormaliseX(const float x, const Sint32 index)
{
    
}

void ClassEngine::LoadShape(const char *path, const Sint32 index)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassEngine::LoadShape(const char*)\n";
#endif

    std::ifstream fin(path, std::ios::binary | std::ios::in | std::ios::ate);
    if (!fin)
    {
        std::cout << "ClassEngine Load error\n";
        return;
    }
    

    fin.close();
}
