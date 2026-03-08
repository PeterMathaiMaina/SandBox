#pragma once 

#include "Shader.h"
#include <cstdint>

namespace Bear {
class OpenGLShader: public Shader{
  OpenGLShader(const std::string& path);
  OpenGLShader(const std::string& name ,const std::sting& vertexpath,const std::string& fragmentpath);

  virtual void Bind() const override;
  virtual void UnBind() const override;


  virtual void SetInt(const std::string& name, int value) override;
  virtual void SetIntArray(const std::string& name, int* values, uint32_t count) override;
  virtual void SetFloat(const std::string& name, float value) override;
  virtual void SetFloat2(const std::string& name, const glm::vec2& value) override;
  virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
  virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
  virtual void SetMat4(const std::string& name, const glm::mat4& value) override;
  
 virtual std::string& const GetName() const {return m_name;}
private:
  std::string m_name;
  uint32_t m_RendererID;
};
}
