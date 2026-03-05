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
  virtual void OnDetach() override;
  virtual void OnAttach() override;
  virtual void OnImGuiDraw() override;
  virtual void OnEvent(Event& e) override;
  virtual void Begin();
  virtual void End();
  void SetDarkThemeColors();
private:
  float m_time = 0.0f;
  bool m_blockEvents;
  bool m_showdemo = true;
};
} // namespace Bear
