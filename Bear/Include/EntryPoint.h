#pragma once 
#include "Engine.h"
#include "Log.h"
#include "Base.h"


namespace Bear{
    Application* CreateApplication();
}

int main()
{
    Bear::Log::Init();
    BEAR_CORE_INFO("Initialised Logger for the engine!"); 
    BEAR_INFO("Initialised Logger for the client!"); 
 
    auto app = Bear::CreateApplication();
    //app->init();
    app->run();
    delete app;
}

