#pragma once 
#include "Engine.h"
#include <stdio.h>
extern Bear::Application* Bear::CreateApplicaton();


int main()
{
    auto app = Bear::CreateApplicaton();
    printf("created application by the entry point");
    app->run();
    delete app;
}


