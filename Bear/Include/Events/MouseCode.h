#pragma once 


#include <cstdint>

#define BEAR_MOUSE_BUTTON_1         0
#define BEAR_MOUSE_BUTTON_2         1
#define BEAR_MOUSE_BUTTON_3         2
#define BEAR_MOUSE_BUTTON_4         3
#define BEAR_MOUSE_BUTTON_5         4
#define BEAR_MOUSE_BUTTON_6         5
#define BEAR_MOUSE_BUTTON_7         6
#define BEAR_MOUSE_BUTTON_8         7
#define BEAR_MOUSE_BUTTON_LAST      BEAR_MOUSE_BUTTON_8
#define BEAR_MOUSE_BUTTON_LEFT      BEAR_MOUSE_BUTTON_1
#define BEAR_MOUSE_BUTTON_RIGHT     BEAR_MOUSE_BUTTON_2
#define BEAR_MOUSE_BUTTON_MIDDLE    BEAR_MOUSE_BUTTON_3

enum class MouseCode : uint16_t{
    left = 0,
    right,
    Middle,
    Button4,
    Button5,
    Button6,
    Button7,
    Button8
};
