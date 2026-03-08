#include "OpenGLContext.h"
#include <iostream>
#include "Headers.h"
#include "Log.h"


namespace Bear {
  OpenGLContext::OpenGLContext(GLFWwindow* WindowHandle)
    : m_window(WindowHandle){};
  void OpenGLContext::SwapBuffers(){
    glfwSwapBuffers(m_window);
  };
  void OpenGLContext::Init(){
    glfwMakeContextCurrent(m_window);
    glewInit();
    BEAR_CORE_INFO("OpenGL Info: ");
    BEAR_CORE_INFO((const char*)glGetString(GL_VENDOR));
    BEAR_CORE_INFO((const char*)glGetString(GL_RENDERER));
    BEAR_CORE_INFO((const char*)glGetString(GL_VERSION));
  };
}
