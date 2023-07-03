#include "ClassEngine.hpp"

ClassEngine::ClassEngine(EngineType type)
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEngine::ClassEngine(EngineType)\n";
#endif

    this->shape = nullptr;
    this->points_amount = 0;

    switch (type)
    {
    case EngineType::R4:
        this->LoadShape("./assets/engine_assets/piston.dat");
        break;

    case EngineType::V8:
        break;

    default:
        break;
    }
}

ClassEngine::~ClassEngine()
{
#ifdef _DVS_DEBUG_
    std::cout << "ClassEngine::~ClassEngine()\n";
#endif

    if (this->shape)
        delete[] this->shape;
    this->shape = nullptr;
}

void ClassEngine::LoadShape(const char *path)
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
    this->points_amount = fin.tellg() / sizeof(SDL_Point);
    fin.seekg(std::ios::beg);

    this->shape = new SDL_Point[this->points_amount];
    SDL_memset(this->shape, 0, this->points_amount);
    for (int i = 0; i < this->points_amount; i++)
    {
        fin.read((char *)&this->shape[i], sizeof(SDL_Point));
    }

    fin.close();
}
