#pragma once 
#include "Renderer/GraphicsContext.h"
#include "Headers.h"


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
