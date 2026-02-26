#include "../../Include/Platforms/Linux/Lin_Windows.h"
#include "Base.h"
#include "Log.h"
#include <iostream>
namespace Bear{ Scope<Window> Window::Create(const WindowProps& props){
#ifdef PLATFORM_LINUX
    return CreateScope<LinuxWindow>(props);
#elif defined(PLATFORM_WINDOWS)
    //return CreateScope<WindowsWindow>(props)}
#endif
}
Window::~Window() = default;
}
