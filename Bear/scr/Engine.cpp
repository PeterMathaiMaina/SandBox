#include "../Include/Engine.h"
#include "ApplicationEvents.h"
#include "Event.h"
#include "KeyEvents.h"
#include "Log.h"
#include <cstdint>
#include <iostream>
namespace Bear{
Application::Application() {
    std::cout << "Engine created!" << std::endl;
} 

Application::~Application() {
    std::cout << "Engine destroyed!" << std::endl;
}

void Application::init() {
    std::cout << "Engine initialized!" << std::endl;
}

void Application::run() {
    std::cout << "Engine running!" << std::endl;
    int keycode = 1;
    bool Repeated = false;
    KeyPressedEvent e(static_cast<KeyCode>(keycode), false);

    if(e.IsInCategory(EventCategoryApplication))
            BEAR_CORE_TRACE("the event is in event category App");
    else {
        BEAR_CORE_TRACE("the event is not an app event");
    }
    while(true){

    }
}
    

}

