#pragma once 
#include "Engine.h"
#include "Event.h"
#include <cstdint>
#include <functional>
#include <sstream>
#include <string>
namespace Bear{
struct WindowProps{
    std::string Title ;
    uint32_t Width;
    uint32_t Height;

    WindowProps(const  std::string& titile = "RETRO",
                uint32_t width = 1600,
                uint32_t height = 900)
                :Title(titile),Width(width),Height(height)
    {

    }
};

class Window{
public:
    using EventCallBackFn  = std::function<Event&>;
    virtual ~Window();
    virtual void OnUpdate();
	virtual uint32_t GetWidth() const = 0;
	virtual uint32_t GetHeight() const = 0;


    //window attributes
    virtual void SetEventCallback();
    virtual void SetVsync(bool enabled) = 0;
    virtual bool IsVsync() const = 0;
    
	virtual void* GetNativeWindow() const = 0;
    

  //  static Scope<Window> Create(const  WindowProps& props = windowProps());
};
};
