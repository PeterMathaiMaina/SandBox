#pragma once 
#include "Engine.h"
#include "Log.h"



extern Bear::Application* Bear::CreateApplicaton();


int main()
{
    Bear::Log::Init();
    BEAR_CORE_INFO("Initialised Logger for the engine!"); 
    BEAR_INFO("Initialised Logger for the client!"); 
    auto app = Bear::CreateApplicaton();
    app->run();
    delete app;
}

