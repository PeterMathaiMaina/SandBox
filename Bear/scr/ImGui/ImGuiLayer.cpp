#include "ImGui/ImGuiLayer.h"
#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"
#include "Base.h"
#include "Engine.h"
#include <GLFW/glfw3.h>
#include <imgui.h>
namespace Bear {

#define BIND_EVENT_FUNC(fn) [this](auto &e) -> bool { return this->fn(e); }
// Recommended bind macro (if not already defined somewhere)

// ------------------------------------------------------------

ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

ImGuiLayer::~ImGuiLayer() {}

void ImGuiLayer::OnAttach() {
  
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();          
    ImGuiIO& io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    // Backend init (example for GLFW + OpenGL)
    GLFWwindow* window  = Application::Get()->GetNativeWind_();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void ImGuiLayer::OnDetach() {}

void ImGuiLayer::OnUpdate() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();


  ImGui::Begin("my first window");
  ImGui::Text("hello, imgui window!!");

  ImGui::End();
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

// ------------------------------------------------------------
// EVENT SYSTEM
// ------------------------------------------------------------

void ImGuiLayer::OnEvent(Event &e) {
  if (!ImGui::GetCurrentContext())
        return; 
  EventDispatcher dispatcher(e);

  dispatcher.Dispatch<MouseButtonPressedEvent>(BIND_EVENT_FUNC(OnMousePressed));
  dispatcher.Dispatch<MouseButtonReleasedEvent>(
      BIND_EVENT_FUNC(OnMouseReleased));
  dispatcher.Dispatch<MouseMovedEvent>(BIND_EVENT_FUNC(OnMouseMoved));
  dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FUNC(OnMouseScrolled));
  dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FUNC(OnKeyPressed));
  dispatcher.Dispatch<KeyReleasedEvent>(BIND_EVENT_FUNC(OnKeyRelease));

  // Block events if ImGui wants them
  ImGuiIO &io = ImGui::GetIO();
  if (io.WantCaptureMouse && e.IsInCategory(EventCategoryMouse))
    e.Handled = true;

  if (io.WantCaptureKeyboard && e.IsInCategory(EventCategoryKeyboard))
    e.Handled = true;
}

// ------------------------------------------------------------
// MOUSE EVENTS
// ------------------------------------------------------------

bool ImGuiLayer::OnMousePressed(MouseButtonPressedEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.MouseDown[static_cast<int>(event.GetMouseButton())] = true;
  return false;
}

bool ImGuiLayer::OnMouseReleased(MouseButtonReleasedEvent &event) {

  ImGuiIO &io = ImGui::GetIO();
  io.MouseDown[static_cast<int>(event.GetMouseButton())] = false;
  return false;
}

bool ImGuiLayer::OnMouseMoved(MouseMovedEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.MousePos = ImVec2(event.GetX(), event.GetY());
  return false;
}

bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent &event) {
  ImGuiIO &io = ImGui::GetIO();
  io.MouseWheelH += event.GetXOffset();
  io.MouseWheel += event.GetYOffset();
  return false;
}

// ------------------------------------------------------------
// KEYBOARD EVENTS
// ------------------------------------------------------------

bool ImGuiLayer::OnKeyPressed(KeyPressedEvent &event) { 

	return false;

}

bool ImGuiLayer::OnKeyRelease(KeyReleasedEvent &event) { return false; }

} // namespace Bear
