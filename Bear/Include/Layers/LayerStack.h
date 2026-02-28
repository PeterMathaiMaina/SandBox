#pragma once 

#include "Layer.h"
#include <vector>

namespace Bear {
class LayerStack{
public:
    LayerStack();
    ~LayerStack();  
    void PushLayer(Layer* layer);
    void PopLayer(Layer* layer);
    void PushOverlay(Layer* overlay);
    void PopOverLay(Layer* overlay);


    std::vector<Layer*>::iterator Begin() {return m_Layers.begin();}
    std::vector<Layer*>::iterator End()   {return m_Layers.end();}
    std::vector<Layer*>::const_iterator begin() const { return m_Layers.begin(); }
    std::vector<Layer*>::const_iterator end() const   { return m_Layers.end(); }

private:
    std::vector<Layer*> m_Layers;
    std::vector<Layer*>::iterator m_LayerInsert;
};
};
