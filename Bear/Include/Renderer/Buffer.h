#pragma once
#include "Base.h" 
#include <cstdint>
#include <type_traits>
namespace Bear{
  class VertexBuffer{
  public:
    virtual ~VertexBuffer() = default;
    virtual void Bind() = 0;
    virtual void UnBind() const = 0;
  };
  class IndexBuffer{
  public:
    virtual IndexBuffer* Create(float* indices,uint32_t size);
    virtual void Bind() const = 0;
    virtual void UnBind() const = 0;
  };
}
