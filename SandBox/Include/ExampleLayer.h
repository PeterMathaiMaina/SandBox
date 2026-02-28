#pragma once
#include "Layers/Layer.h"
class ExampleLayer : public Bear::Layer
{
public:
    ExampleLayer();

    void OnUpdate() override;
    void OnEvent(Bear::Event& e) override;
    bool IfOverlay() const;
};
