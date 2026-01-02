#include "../Include/Engine.h"
#include <iostream>
namespace Bear{
Application::Application() {
    std::cout << "Engine created!" << std::endl;
} 

Application::~Application() {
    std::cout << "Engine destroyed!" << std::endl;
}

void Application::init() {
    std::cout << "Engine initialized!" << std::endl;
}

void Application::run() {
    std::cout << "Engine running!" << std::endl;
    while(true){

    }
}
    

}

