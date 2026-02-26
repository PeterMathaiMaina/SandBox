#pragma once
#include "Events/ApplicationEvents.h"
namespace Bear{
class Application {
public:
    Application();
    virtual ~Application();
    void init();
    void run();
};
//TO BE DEFINED IN THE CLIENT 
Application* CreateApplicaton();

}
