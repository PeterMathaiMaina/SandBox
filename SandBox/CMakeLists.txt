cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_CXX_STANDARD 20)
project(SandBox)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(SandBox scr/Application.cpp
                        scr/Layers/ExampleLayer.cpp)


target_include_directories(SandBox PRIVATE
   # ${CMAKE_SOURCE_DIR}/scr/BackEnd
   ../Bear/Include/
   ../Bear/Include/Events/
   Include/
)   

target_link_libraries(SandBox PRIVATE Bear)
                                
