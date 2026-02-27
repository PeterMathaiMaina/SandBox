#include "../../../Include/Platforms/Linux/Lin_Windows.h"
#include "ApplicationEvents.h"
#include "GLFW/glfw3.h"
#include "KeyCodes.h"
#include "Log.h"
#include <GL/gl.h>
#include <cstdint>
#include "MouseCode.h"
#include "MouseEvent.h"
#include "KeyEvents.h"

namespace Bear{
static uint8_t s_GLFWwindowcount  = 0;
static void GLFWErrorCallBack(int error,const char* description){
    BEAR_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
}


static bool s_GLFWInitialized = false ;


LinuxWindow::LinuxWindow(const WindowProps& props){
    Init(props);
}


void LinuxWindow::Init(const WindowProps& props){
    m_Data.Title = props.Title;
    m_Data.Height = props.Height;
    m_Data.Width = props.Width;


    BEAR_CORE_INFO("Creating window {0}, {1}, {2}",props.Title,props.Width,props.Height);
    if (s_GLFWwindowcount == 0){
        int success = glfwInit();
        if (!success){
            BEAR_CORE_ERROR("FAILED TO INITIALIZE THE GLFW WINDOW");
        }
        glfwSetErrorCallback(GLFWErrorCallBack);
    }
    

    m_Window =glfwCreateWindow(props.Width,props.Height,props.Title.c_str(),nullptr,nullptr);
    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window,&m_Data);
    SetVsync(true);


    //SET GLFW CALLBACKS
    glfwSetWindowSizeCallback(m_Window, 
    [](GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width,height);
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        data.Height = height;
        data.Width  = width;
        WindowResizeEvent event(width,height);
        data.EventCallBack(event);
    });
    

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window){
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        WindowCloseEvent event;
        data.EventCallBack(event);
    });

    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

    switch (action)
    {
        case GLFW_PRESS:
        {
            KeyPressedEvent event(static_cast<KeyCode>(key), false);
            data.EventCallBack(event);
            break;
        }
        case GLFW_RELEASE:
        {
            KeyReleasedEvent event(static_cast<KeyCode>(key));
            data.EventCallBack(event);
            break;
        }
        case GLFW_REPEAT:
        {
            KeyPressedEvent event(static_cast<KeyCode>(key), true);
            data.EventCallBack(event);
            break;
        }
    }
    });

    glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        KeyTypedEvent event(static_cast<KeyCode>(keycode));
        data.EventCallBack(event);
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        switch (action)
        {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent event(static_cast<MouseCode>(button));
                data.EventCallBack(event);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent event(static_cast<MouseCode>(button));
                data.EventCallBack(event);
                break;
            }
        }
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        MouseScrolledEvent event((float)xOffset, (float)yOffset);
        data.EventCallBack(event);
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
    {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

        MouseMovedEvent event((float)xPos, (float)yPos);
        data.EventCallBack(event);
    });


    glfwSwapBuffers(m_Window);
}
void LinuxWindow::SetVsync(bool enabled){
    if (enabled){
        glfwSwapInterval(1);
    }
    else {
        glfwSwapInterval(0);
    }
    m_Data.VSync = enabled;
}
LinuxWindow::~LinuxWindow(){
    ShutDown(); 
}
 void LinuxWindow::OnUpdate(){
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}
void LinuxWindow::ShutDown(){
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}
 bool LinuxWindow::IsVsync() const{
    return m_Data.VSync;
}


};
