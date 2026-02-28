#include "ExampleLayer.h"
#include <iostream>
ExampleLayer::ExampleLayer()
    : Layer("ExampleLayer",false)
{
}

void ExampleLayer::OnUpdate()
{
    std::cout<<"ExampleLayer::OnUpdate\n";
}

void ExampleLayer::OnEvent(Bear::Event& e)
{
    std::cout<<"ExampleLayer::OnEvent - {0}"<< e.GetName()<<'\n';
}
bool ExampleLayer::IfOverlay() const  {return m_IsOverlay;}
