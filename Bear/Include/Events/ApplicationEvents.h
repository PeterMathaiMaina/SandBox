#pragma once

#include "Event.h"  // Ensure this includes the Event base class
#include <string>
#include <sstream>  // For stringstream in ToString()

namespace Bear {

    // WindowResizeEvent class
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height);

        unsigned int GetWidth() const;
        unsigned int GetHeight() const;

        std::string ToString() const override;

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        unsigned int m_Width, m_Height;
    };

    // WindowCloseEvent class
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent();

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    // AppTickEvent class
    class AppTickEvent : public Event
    {
    public:
        AppTickEvent();

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    // AppUpdateEvent class
    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent();

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    // AppRenderEvent class
    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent();

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

}

