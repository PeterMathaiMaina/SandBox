#pragma once 
#include "Event.h"
#include "Base.h"
#include "Log.h"
#include <functional>
#include <sstream>
#include <string>
namespace Bear{
struct WindowProps{
    std::string Title ;
    uint32_t Width;
    uint32_t Height;

    WindowProps(const  std::string& title = "SANDBOX",
                uint32_t width = 1600,
                uint32_t height = 900)
                :Title(title),Width(width),Height(height)
    { 
    }
};

class Window{
public:
    using EventCallBackFn  = std::function<void(Event&)>;
    virtual ~Window();
    virtual void OnUpdate() = 0;
	virtual uint32_t GetWidth() const = 0;
	virtual uint32_t GetHeight() const = 0;

    
    //window attributes
    virtual void SetEventCallback(const EventCallBackFn& callback) = 0;
    virtual void SetVsync(bool enabled) = 0;
    virtual bool IsVsync() const = 0;
    
	virtual void* GetNativeWindow() const = 0;
    

    static Scope<Window> Create(const  WindowProps& props = WindowProps());
};
};
