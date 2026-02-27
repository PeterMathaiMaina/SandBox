#pragma once 
#include <string>
#include <sstream>
#include <memory>
namespace Bear{

}

template<typename T>
using Scope = std::unique_ptr<T>;

#define EVENT_CLASS_TYPE(type) \
    static EventType GetStaticType() { return EventType::type; } \
    virtual EventType GetEventType() const override { return GetStaticType(); } \
    virtual const char* GetName() const override { return #type; }


#define EVENT_CLASS_CATEGORY(category) \
    virtual int GetCategoryFlags() const override { return category; }
#if defined(_WIN32)
    #define PLATFORM_WINDOWS
#elif defined(__linux__)
    #define PLATFORM_LINUX
#elif defined(__APPLE__)
    #define PLATFORM_MAC
#else
    #error "Unknown platform!"
#endif

template<typename T, typename ...Args>
constexpr Scope<T> CreateScope(Args&& ...args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

#define BIT(x) (1 << x)



