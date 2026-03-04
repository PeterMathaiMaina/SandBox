#include "Input.h"
#include "Engine.h"
#include "KeyCodes.h"
#include <GLFW/glfw3.h>
#include <utility>
#include "MouseCode.h"
#include "Window.h"



namespace Bear {
  Input* Input::s_Instance = new Input(); 
  bool Input::IsKeyPressed(KeyCode& button){
    auto& window  = Application::Get()->GetWindow();
    
    int state = glfwGetKey(static_cast<GLFWwindow*>(window.GetNativeWindow()), static_cast<int>(button));
    return state == GLFW_PRESS || state == GLFW_REPEAT;
  }

  std::pair<float,float> Input::GetMousePosition(){
    double X,Y;
    return std::make_pair((float)X,(float)Y);
  }
  float Input::GetXPos(){
    auto[x,y] = GetMousePosition();
    return x;
  }
  float Input::GetYPos(){
    auto[x,y] = GetMousePosition();
    return y;
  }
  bool Input::IsMousePressed(MouseCode &button){
    GLFWwindow* native_window  = static_cast<GLFWwindow*>(Application::Get()->GetWindow().GetNativeWindow());
    int state = glfwGetMouseButton(native_window,static_cast<int>(button));
    return state == GLFW_PRESS || state == GLFW_REPEAT;
  }
}


