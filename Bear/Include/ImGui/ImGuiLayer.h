#pragma once
#include "Event.h"
#include "KeyEvents.h"
#include "Layers/Layer.h"
#include "MouseEvent.h"

namespace Bear {
class ImGuiLayer : public Layer {
public:
  ImGuiLayer();
  ~ImGuiLayer();
  void OnDetach() override;
  void OnAttach() override;
  void OnUpdate() override;
  void OnEvent(Event &e) override;

private:
  bool OnMousePressed(MouseButtonPressedEvent &event);
  bool OnMouseReleased(MouseButtonReleasedEvent &event);
  bool OnMouseMoved(MouseMovedEvent &event);
  bool OnMouseScrolled(MouseScrolledEvent &event);
  bool OnKeyPressed(KeyPressedEvent &event);
  bool OnKeyRelease(KeyReleasedEvent &event);
  bool OnKeyTyped(KeyTypedEvent &event);

private:
  float m_time = 0.0f;
};
} // namespace Bear
