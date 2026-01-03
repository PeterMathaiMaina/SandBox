#include "Event.h"
#include <string>

namespace Bear{
class MouseMovedEvent : public Event{
public:
    MouseMovedEvent(float x,float y);
    inline float GetX() const {return m_MouseX;} 
    
    inline float GetY() const {return m_MouseY;} 
    

    std::string ToString() const override;
    EVENT_CLASS_TYPE(MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
 
private:
    float m_MouseX , m_MouseY;
}; 
class MouseScrolledEvent : public Event{
public:
    MouseScrolledEvent(float xOffset,float yOffset);

    inline float GetXOffset() const {return m_xOffset;} 
    
    inline float GetYOffset() const {return m_yOffset;} 
    

    std::string ToString() const override;
    EVENT_CLASS_TYPE(MouseScrolled)
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
 
private:
    float m_xOffset,m_yOffset;
}; 
class MouseButtonEvent : public Event{
public:
    inline int GetMouseButton() const {return m_Button;}

    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
protected:
    MouseButtonEvent(int Button)
        : m_Button(Button){}
    int m_Button;
};
class MouseButtonPressedEvent : public MouseButtonEvent{
public:
    MouseButtonPressedEvent(int Button);    
    std::string ToString() const override;
    EVENT_CLASS_TYPE(MouseButtonPressed);

};
class MouseButtonReleasedEvent : public MouseButtonEvent{
public:
    MouseButtonReleasedEvent(int Button);    
    std::string ToString() const override;
    EVENT_CLASS_TYPE(MouseButtonReleased);

};
}
