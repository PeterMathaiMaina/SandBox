#include "ApplicationEvents.h"
#include "Engine.h"
#include "EntryPoint.h"
#include "Event.h"
#include "ExampleLayer.h"
#include "ImGui/ImGuiLayer.h"
#include "KeyCodes.h"
#include "Layers/Layer.h"
#include "Layers/LayerStack.h"
#include "Log.h"
#include "MouseCode.h"
#include "Window.h"
#include <GLFW/glfw3.h>
#include <cstddef>
#include <glm/ext/matrix_float4x4.hpp>
#include <iostream>
#include <memory>
#include "Input.h"
#include "MouseCode.h"
#include "glm/fwd.hpp"
#include "glm/glm.hpp"
// Sandbox Application (Client Side)
class SandBox : public Bear::Application {
public:
  SandBox() {
    PushLayer(new ExampleLayer());
  };
  ~SandBox() override = default;
};
// Factory Function (Called by EntryPoint.h)
namespace Bear {
Application *CreateApplication() { return new SandBox(); }
}
// Engine Implementation
namespace Bear {
#define BIND_EVENT_FUNC(x)                                                     \
  std::bind(&Application::x, this, std::placeholders::_1)

Application *Application::s_Instance = nullptr;

Application::Application() {
  std::cout << "Engine created!" << std::endl;
  m_Window = Window::Create();
  m_Window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));
  s_Instance = this;
  m_ImguiLayer = new ImGuiLayer();
  m_LayerStack.PushLayer(m_ImguiLayer); 
  m_ImguiLayer->OnAttach();
}

Application::~Application() { std::cout << "Engine destroyed!" << std::endl; }

void Application::init() { std::cout << "Engine initialized!" << std::endl; }

Application *Application::Get() { return s_Instance; }

void Application::OnEvent(Event &e) {
  EventDispatcher dispatcher(e);
  dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

  for (auto it = m_LayerStack.End(); it != m_LayerStack.Begin();) {
    (*--it)->OnEvent(e);
    if (e.Handled) {
      break;
    }
  }
}

void Application::PushLayer(Layer *layer) {
  layer->OnAttach();
  m_LayerStack.PushLayer(layer);
}



void Application::Pushoverlay(Layer *overlay) {
  overlay->OnAttach();
  m_LayerStack.PushOverlay(overlay);
}



void Application::run() {
  std::cout << "Engine running!" << std::endl;

  int keycode = 1;

  KeyPressedEvent e(static_cast<KeyCode>(keycode), false);

  float frame_time = 0.0f;

  while (m_running) {
    m_Window->OnUpdate();
    for (Layer *layer : m_LayerStack) {
      layer->OnUpdate();
    }
    m_ImguiLayer->Begin();
      for (Layer *layer : m_LayerStack) {
        layer->OnImGuiDraw();
      }
    m_ImguiLayer->End();

  }
}
bool Application::OnWindowClose(WindowCloseEvent &e) {
  m_running = false;
  return true;
}

}
