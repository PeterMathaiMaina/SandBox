#pragma once

#include "Events/ApplicationEvents.h"
#include "Event.h"
#include "KeyEvents.h"
#include "Log.h"
#include "Window.h"

#include <cstdint>
#include <iostream>
#include <memory>

namespace Bear {

class Application
{
public:
    Application();
    virtual ~Application(); // must define in Application.cpp
    //
    void init();
    void run();
    void OnEvent(Event& e);
private:
    std::unique_ptr<Window> m_Window; // okay with forward-declared Window if destructor out-of-line
    bool m_running = true;
};

}
