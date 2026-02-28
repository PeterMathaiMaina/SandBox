#pragma once 
#include "Base.h"
#include "Event.h"

namespace  Bear{
class Layer{
public:
    Layer(const std::string& name = "layer",bool overlay = false);
    virtual ~Layer();

    virtual void OnAttach(){};
    virtual void OnDetach(){};
    virtual void OnUpdate(){};
    bool IsOverLay() const ;
    virtual void OnEvent(Event& e){};
    inline const std::string& GetName() const {return m_DebugName;};
private:
    std::string m_DebugName;
protected:
    bool m_IsOverlay;
};
};
