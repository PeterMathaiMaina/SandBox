#include "../Include/Events/Event.h"

namespace Bear {

std::string Event::ToString() const {
    return GetName();
}

EventDispatcher::EventDispatcher(Event& event)
    : m_Event(event) {}

template<typename T>
bool EventDispatcher::Dispatch(const EventFn& func) {
    if (m_Event.GetEventType() == T::GetStaticType()) {
        // Using dynamic_cast to ensure type safety
        T& event = dynamic_cast<T&>(m_Event); // Ensure the event is of the correct type
        m_Event.m_Handled = func(event);  // Pass event to the function
        return true;
    }
    return false;
}

} // namespace Bear

