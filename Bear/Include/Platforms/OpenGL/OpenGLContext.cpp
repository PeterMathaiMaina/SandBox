#include "OpenGLContext.h"

namespace Bear {
  OpenGLContext::OpenGLContext(GLFWwindow* WindowHandle)
    : m_window(WindowHandle){};
  void OpenGLContext::SwapBuffers(){};
  void OpenGLContext::Init(){
    glfwMakeContextCurrent(m_window);
  };
}
