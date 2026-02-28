#include "Layers/Layer.h"


namespace Bear {
Layer::Layer(const  std::string& DebugName,bool overlay)
    :m_DebugName(DebugName), m_IsOverlay(overlay){}
Layer::~Layer(){}
bool Layer::IsOverLay() const {return m_IsOverlay;}

}
