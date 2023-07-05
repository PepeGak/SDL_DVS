#include "ClassEngine.hpp"

ClassEngine::ClassEngine(EngineType type)
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEngine::ClassEngine(EngineType)\n";
#endif

    switch (type)
    {
    case EngineType::R4:
        //Внешний каркас, Коленвал, Шатун, Поршень, Клапаны, Верх
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
        this->LoadShape("./assets/engine_assets/R4/engine_body.dat", 0);
        this->LoadShape("./assets/engine_assets/R4/piston.dat", 1);
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
        if (i.shape)
            delete[] i.shape;
        i.pointAmount = 0;
        i.shape = nullptr;
    }
    this->engineParts.clear();
    
}

void ClassEngine::Normalise(const SDL_Point &centre, const Sint32 index)
{
    for (int i = 0; i < this->engineParts[index].pointAmount; i++)
    {
        this->engineParts[index].shape[i].x += centre.x;
        this->engineParts[index].shape[i].y += centre.y;
    }
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
    this->engineParts[index].pointAmount = fin.tellg() / sizeof(SDL_Point);
    fin.seekg(std::ios::beg);

    this->engineParts[index].shape = new SDL_Point[this->engineParts[index].pointAmount];
    SDL_memset(this->engineParts[index].shape, 0, this->engineParts[index].pointAmount);
    for (int i = 0; i < this->engineParts[index].pointAmount; i++)
    {
        fin.read((char *)&this->engineParts[index].shape[i], sizeof(SDL_Point));
    }

    fin.close();
}
