#include "../Include/Events/MouseEvent.h"
#include <sstream>

namespace Bear{
std::string MouseMovedEvent::ToString() const {
    std::stringstream ss;
    ss << "MouseMovedEvent: " << m_MouseX << " , " << m_MouseY; 
    return ss.str();
}
MouseMovedEvent::MouseMovedEvent(float x,float y)
    :m_MouseX(x) ,m_MouseY(y){}




std::string MouseScrolledEvent::ToString() const {
    
    std::stringstream ss;
    ss << "MouseScrolledEvent: " << GetXOffset() << " , " <<GetYOffset(); 
    return ss.str();
}
MouseScrolledEvent::MouseScrolledEvent(float xOffset,float yOffset)
    :m_xOffset(xOffset) ,m_yOffset(yOffset){}




std::string MouseButtonPressedEvent::ToString() const {
    std::stringstream ss;
    ss << "MouseButtonPressedEvent: " << m_Button; 
    return ss.str();
}
MouseButtonPressedEvent::MouseButtonPressedEvent(int Button )
        :MouseButtonEvent(Button){}



// Constructor for MouseButtonReleasedEvent
MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button)
    : MouseButtonEvent(button) {}  // Forwarding button to the base class constructor

// Override ToString method
std::string MouseButtonReleasedEvent::ToString() const {
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent: " << m_Button;
    return ss.str();
}
}


