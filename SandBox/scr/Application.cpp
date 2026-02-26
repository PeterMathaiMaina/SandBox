#include <iostream>
#include <memory>
#include <GLFW/glfw3.h>
#include "Engine.h"
#include "EntryPoint.h"
#include "ApplicationEvents.h"
#include "Window.h"
////////////////////////////////////////////////////////////
// Sandbox Application (Client Side)
////////////////////////////////////////////////////////////

class SandBox : public Bear::Application
{
public:
    SandBox() = default;
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

Application::Application()
{
    std::cout << "Engine created!" << std::endl;
    m_Window = Window::Create();
}

Application::~Application()
{
     
    std::cout << "Engine destroyed!" << std::endl;
}

void Application::init()
{ 
    //std::cout << "THE WINDOW CRY CRY\n";
    std::cout << "Engine initialized!" << std::endl;
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


} // namespace Bear
