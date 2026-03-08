#pragma once 
#include "Renderer/Buffer.h"
#include <cstdint>

namespace Bear {
  class OpenGLVertexBuffer : public VertexBuffer{
  public:
    ~OpenGLVertexBuffer() override;
    OpenGLVertexBuffer(float* vertices,uint32_t size);
    virtual void Bind() override;
    virtual void UnBind() const   override;
    static VertexBuffer* Create(float* vertices,uint32_t size) {return new OpenGLVertexBuffer(vertices,size);};
  private:
    uint32_t m_RendererID;
  };
}
