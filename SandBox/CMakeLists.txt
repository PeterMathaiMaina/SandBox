cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_CXX_STANDARD 20)



project(SandBox)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(SandBox scr/Main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(assimp REQUIRED)
find_package(glm REQUIRED)

include_directories(${GLM_INCLUDE_DIRS})


target_include_directories(SandBox PRIVATE
   # ${CMAKE_SOURCE_DIR}/scr/BackEnd
)   

target_link_libraries(SandBox PRIVATE 
                                glfw
                                OpenGL::GL
                                GLEW::GLEW)
                                
