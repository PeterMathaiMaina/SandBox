#include "../Include/Events/ApplicationEvents.h"
#include <sstream>

namespace Bear {

    // Constructor for WindowResizeEvent
    WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height)
        : m_Width(width), m_Height(height) {}

    // Getter for Width
    unsigned int WindowResizeEvent::GetWidth() const { return m_Width; }

    // Getter for Height
    unsigned int WindowResizeEvent::GetHeight() const { return m_Height; }

    // ToString implementation for WindowResizeEvent
    std::string WindowResizeEvent::ToString() const
    {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
        return ss.str();
    }

    // Default constructor for WindowCloseEvent
    WindowCloseEvent::WindowCloseEvent() = default;

    // Default constructor for AppTickEvent
    AppTickEvent::AppTickEvent() = default;

    // Default constructor for AppUpdateEvent
    AppUpdateEvent::AppUpdateEvent() = default;

    // Default constructor for AppRenderEvent
    AppRenderEvent::AppRenderEvent() = default;

}

