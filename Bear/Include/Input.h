#pragma once 

#include "KeyCodes.h"
#include "MouseCode.h"
#include "Window.h"
#include "Event.h"
#include <iostream>
#include <utility>

namespace Bear{
  class Input {
  public:
    Input() = default;
    static bool IsMousePressed(MouseCode& button);
    static bool IsKeyPressed(KeyCode& button);
    static float GetXPos();
    static float GetYPos();
    static std::pair<float, float> GetMousePosition();
  private:
    static Input* s_Instance;
  };
}
