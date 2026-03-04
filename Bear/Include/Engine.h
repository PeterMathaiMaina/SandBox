#pragma once

#include "Events/ApplicationEvents.h"
#include "Event.h"
#include "KeyEvents.h"
#include "Layers/Layer.h"
#include "Log.h"
#include "Platforms/Linux/Lin_Windows.h"
#include "Window.h"
#include "Layers/LayerStack.h"
#include "imgui_impl_glfw.h"
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
    static Application* Get();

    GLFWwindow* GetNativeWind_() const {return static_cast<GLFWwindow*>(m_Window->GetNativeWindow());};
    Window& GetWindow() const {return *m_Window;};
    void init();
    void run();
    void OnEvent(Event& e);
    void PushLayer(Layer* layer);
    void Pushoverlay(Layer* overlay);
    bool OnWindowClose(WindowCloseEvent& e);
private:
    std::unique_ptr<Window> m_Window; // okay with forward-declared Window if destructor out-of-line
    LayerStack m_LayerStack;
    bool m_running = true;
    static Application* s_Instance;
};

}
