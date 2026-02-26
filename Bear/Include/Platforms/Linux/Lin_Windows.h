#pragma once 
#include "../Window.h"
#include <string>
#include <GLFW/glfw3.h>

namespace Bear{
class LinuxWindow : public Window{
public:
    LinuxWindow(const WindowProps& props);
    virtual ~LinuxWindow();
    void OnUpdate() override;
    inline unsigned int GetWidth() const override {return m_Data.Width;}
    inline unsigned int GetHeight() const override {return m_Data.Height;}
    virtual void* GetNativeWindow() const override {return m_Window;};

    //window attributes
    void SetEventCallback(const EventCallBackFn& callback) override {m_Data.EventCallBack = callback;};
    void SetVsync(bool enabled) override;
    bool IsVsync() const override;
    


private:
     //Scope<GraphicsContext> m_context;
    virtual void Init(const WindowProps& props);
    virtual void ShutDown();



    GLFWwindow* m_Window;



    struct WindowData{
        unsigned int Width,Height;
        std::string Title;
        bool VSync;

        EventCallBackFn EventCallBack;
    };
    WindowData m_Data;
};
};
