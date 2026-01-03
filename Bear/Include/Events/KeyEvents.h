#pragma once

#include "Event.h"
#include <sstream>
#include <string>

namespace Bear {

class KeyEvent : public Event {
public:
    inline int GetKeyCode() const { return m_KeyCode; }

protected:
    KeyEvent(int keycode);
    int m_KeyCode;
};

class KeyPressedEvent : public KeyEvent    {
private:
    int m_repeatCount;

public:
    KeyPressedEvent(int keycode, int repeatCount);

    inline int GetRepeatCount() const { return m_repeatCount; }
    std::string ToString() const override;

    EVENT_CLASS_TYPE(KeyPressed)
};

class KeyReleaseEvent : public KeyEvent {
public:
    KeyReleaseEvent(int keycode);

    std::string ToString() const override;

    EVENT_CLASS_TYPE(KeyReleased)
};

}

