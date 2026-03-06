#pragma once 
#include "Renderer/GraphicsContext.h"
#include <GLFW/glfw3.h>



namespace Bear{
  class OpenGLContext : public GraphicsContext{
  public:
    OpenGLContext(GLFWwindow* WindowHandle);
    void Init() override;
    void SwapBuffers() override;
  private:
    GLFWwindow* m_window;
  };

}
