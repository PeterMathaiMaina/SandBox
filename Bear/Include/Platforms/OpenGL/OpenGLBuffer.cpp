#include "OpenGLBuffer.h"
#include "Headers.h"
#include <cstdint>
namespace Bear {
  void OpenGLVertexBuffer::Bind() {
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
  }
  void OpenGLVertexBuffer::UnBind() const {
    glBindBuffer(GL_ARRAY_BUFFER,0);
  }
  
}
