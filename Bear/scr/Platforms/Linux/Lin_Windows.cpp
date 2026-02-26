#include "../../../Include/Platforms/Linux/Lin_Windows.h"
#include "GLFW/glfw3.h"
#include "Log.h"
#include <cstdint>


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
        
}
void LinuxWindow::OnUpdate(){
    glfwPollEvents();
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
void LinuxWindow::ShutDown(){
    glfwDestroyWindow(m_Window);
}
 bool LinuxWindow::IsVsync() const{
    return m_Data.VSync;
}


};
