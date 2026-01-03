#pragma once

#include "../Engine.h"
#include "../Core.h"
#include <string>
#include <functional>
#include "Event.h"

namespace Bear {

enum class EventType {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
};

enum EventCategory {
    None = 0,
    EventCategoryApplication = BIT(0),
    EventCategoryInput = BIT(1),
    EventCategoryKeyBoard = BIT(2),
    EventCategoryMouse = BIT(3),
    EventCategoryMouseButton = BIT(4)
};

#define EVENT_CLASS_TYPE(type) \
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }


#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }

class Event {
    friend class EventDispatcher;

public:
    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual std::string ToString() const;

    inline bool isInCategory(EventCategory category) {
        return GetCategoryFlags() & category;
    }

protected:
    bool m_Handled = false;
};

// The EventDispatcher
class EventDispatcher {
public:
    using EventFn = std::function<bool(Event&)>;

    EventDispatcher(Event& event);

    template<typename T>
    bool Dispatch(const EventFn& func);

private:
    Event& m_Event; // Store reference to the event
};

}

