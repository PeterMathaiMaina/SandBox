#include "../Include/Events/KeyEvents.h"


namespace Bear {

KeyEvent::KeyEvent(int keycode) 
    : m_KeyCode(keycode) {}

KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount)
    : KeyEvent(keycode), m_repeatCount(repeatCount) {}

std::string KeyPressedEvent::ToString() const {
    std::stringstream ss;
    ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_repeatCount << " repeats)";
    return ss.str();
}

KeyReleaseEvent::KeyReleaseEvent(int keycode)
    : KeyEvent(keycode) {}

std::string KeyReleaseEvent::ToString() const {
    std::stringstream ss;
    ss << "KeyReleasedEvent: " << m_KeyCode;
    return ss.str();
}

}


