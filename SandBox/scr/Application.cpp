#include <iostream>
#include "Engine.h"
#include "EntryPoint.h"
#include "ApplicationEvents.h"

class SandBox : public Bear::Application {
public:
    SandBox()
    {

    }
    ~SandBox()
    {

    }
    
    
} ;

Bear::Application* Bear::CreateApplicaton(){
    return new SandBox;
}


