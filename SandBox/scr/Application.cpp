#include <cstddef>
#include <iostream>
#include <memory>
#include <GLFW/glfw3.h>
#include "Engine.h"
#include "EntryPoint.h"
#include "ApplicationEvents.h"
#include "Event.h"
#include "Layers/Layer.h"
#include "Log.h"
#include "Window.h"
#include "Layers/LayerStack.h"
#include "ExampleLayer.h"
////////////////////////////////////////////////////////////
// Sandbox Application (Client Side)
////////////////////////////////////////////////////////////

class SandBox : public Bear::Application
{
public:
    SandBox() 
    {
        PushLayer(new ExampleLayer());
    };
    ~SandBox() override = default;
};

////////////////////////////////////////////////////////////
// Factory Function (Called by EntryPoint.h)
////////////////////////////////////////////////////////////

namespace Bear
{
    Application* CreateApplication()
    {
        return new SandBox();
    }
}

////////////////////////////////////////////////////////////
// Engine Implementation
////////////////////////////////////////////////////////////

namespace Bear
{
#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)
Application::Application()
{
    std::cout << "Engine created!" << std::endl;
    m_Window = Window::Create();
    m_Window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));

}

Application::~Application()
{
     
    std::cout << "Engine destroyed!" << std::endl;
}

void Application::init()
{ 
    std::cout << "Engine initialized!" << std::endl;
}
void Application::OnEvent(Event& e){
    EventDispatcher dispatcher(e);
    dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));
    BEAR_INFO("{0} ",e.GetName());
    

    for (auto it  = m_LayerStack.End(); it != m_LayerStack.Begin(); ){
        (*--it)->OnEvent(e);
        if(e.Handled){
            break;
        }

    }


}

void Application::PushLayer(Layer* layer){
    m_LayerStack.PushLayer(layer);
}

void Application::Pushoverlay(Layer* overlay){
    m_LayerStack.PushOverlay(overlay);
}

void Application::run()
{
    std::cout << "Engine running!" << std::endl;

    int keycode = 1;

    KeyPressedEvent e(static_cast<KeyCode>(keycode), false);

    if (e.IsInCategory(EventCategoryApplication))
        BEAR_CORE_TRACE("The event is in Application category");
    else
        BEAR_CORE_TRACE("The event is NOT in Application category");

    while (m_running)
    {
        m_Window->OnUpdate();

        for (Layer* layer : m_LayerStack) {
            if(layer->IsOverLay()){
                std::cout<<"it is overlay\n";
            }
        }


        // --- Begin OpenGL commands ---
        // Clear screen
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw something simple (e.g., colored triangle)
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
            glColor3f(0.0f, 1.0f, 0.0f); glVertex2f( 0.5f, -0.5f);
            glColor3f(0.0f, 0.0f, 1.0f); glVertex2f( 0.0f,  0.5f);
        glEnd();
    }
}
bool Application::OnWindowClose(WindowCloseEvent& e){
    m_running = false;
    return true;
}

} // namespace Bear
