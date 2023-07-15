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
        this->LoadShape("./assets/engine_assets/R4/engine_head.dat", 2);
        this->LoadShape("./assets/engine_assets/R4/crank.dat", 3);
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

float ClassEngine::GetPartWidth(const Sint32 index)
{
    float max = this->engineParts[index].shape[0].x;
    float min = max;
    for (Sint32 i = 0; i < this->engineParts[index].pointAmount; i++)
    {
        if (this->engineParts[index].shape[i].x >= max)
            max = this->engineParts[index].shape[i].x;
        if (this->engineParts[index].shape[i].x <= min)
            min = this->engineParts[index].shape[i].x;
    }
    return max - min;
}

float ClassEngine::GetPartHeight(const Sint32 index)
{
    float max = this->engineParts[index].shape[0].y;
    float min = max;
    for (Sint32 i = 0; i < this->engineParts[index].pointAmount; i++)
    {
        if (this->engineParts[index].shape[i].y >= max)
            max = this->engineParts[index].shape[i].y;
        if (this->engineParts[index].shape[i].y <= min)
            min = this->engineParts[index].shape[i].y;
    }
    return max - min;
}

void ClassEngine::Normalise(const float x, const float y, const Sint32 index)
{
    if (this->engineParts[index].shape)
        this->engineParts[index].centre = {x, y};
}

void ClassEngine::NormaliseY(const float y, const Sint32 index)
{
    if (this->engineParts[index].shape)
        for (Sint32 i = 0; i < this->engineParts[index].pointAmount; i++)
            this->engineParts[index].shape[i].y += y;
}

void ClassEngine::Scale(const float k, const Sint32 index)
{
    if (this->engineParts[index].shape)
        for (Sint32 i = 0; i < this->engineParts[index].pointAmount; i++)
        {
            this->engineParts[index].shape[i].x *= (k < 0 ? -k : k);
            this->engineParts[index].shape[i].y *= (k < 0 ? -k : k);
        }
}

void ClassEngine::Scale(const float k)
{
    for (Sint32 i = 0; i < this->engineParts.size(); i++)
        if(this->engineParts[i].shape)
            for (Sint32 index = 0; index < this->engineParts[i].pointAmount; index++)
            {
                this->engineParts[i].shape[index].x *= (k < 0 ? -k : k);
                this->engineParts[i].shape[index].y *= (k < 0 ? -k : k);
            }
}

void ClassEngine::NormaliseX(const float x, const Sint32 index)
{
    if (this->engineParts[index].shape)
        for (Sint32 i = 0; i < this->engineParts[index].pointAmount; i++)
            this->engineParts[index].shape[i].x += x;
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
    this->engineParts[index].pointAmount = fin.tellg() / sizeof(SDL_FPoint);
    fin.seekg(std::ios::beg);

    this->engineParts[index].shape = new SDL_FPoint[this->engineParts[index].pointAmount];
    SDL_memset(this->engineParts[index].shape, 0, this->engineParts[index].pointAmount);
    for (Sint32 i = 0; i < this->engineParts[index].pointAmount; i++)
    {
        fin.read((char *)&this->engineParts[index].shape[i], sizeof(SDL_FPoint));
    }

    fin.close();
}
