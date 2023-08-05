#include "ClassMain.hpp"

void ClassMain::onEvent(SDL_Event *ev)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onEvent()\n";
#endif

    ClassMain::ClassEvent::onEvent(ev);
}

void ClassMain::onExit()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onExit()\n";
#endif

    this->appRunning = false;
}

void ClassMain::onLMouseDown(Sint32 xm, Sint32 ym)
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onLMouseDown(Sint32, Sint32)\n";
#endif
}

void ClassMain::onKeyHDown()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onKeyHDown()\n";
#endif

}

void ClassMain::onKeyRDown()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onKeyRDown()\n";
#endif

    this->kW = !this->kW;
}

void ClassMain::onKeyQDown()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onKeyQDown()\n";
#endif

    this->animation_on = !this->animation_on;
}

void ClassMain::onArrowUpDown()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onArrowUpDown()\n";
#endif

    this->en->SetRPM(this->en->GetRPM() + 10);
}

void ClassMain::onArrowDownDown()
{
#ifdef _DVS_DEBUG_
    std::cout << "void ClassMain::onArrowDownDown()\n";
#endif

    this->en->SetRPM(this->en->GetRPM() - 10);
    if(this->en->GetRPM() < 0)
    {
        this->en->SetRPM(0);
        this->animation_on = false;
    }
}
