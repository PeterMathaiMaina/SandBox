# /GameEngine/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(Bear)

set(CMAKE_CXX_STANDARD 17)
find_package(GLEW REQUIRED)
find_package(assimp REQUIRED)
find_package(glm REQUIRED)

include_directories(${GLM_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
# Set policy to prefer GLVND (Modern OpenGL)
cmake_policy(SET CMP0072 NEW)

add_library(Bear SHARED
    scr/Engine.cpp
    Include/Engine.h
)

target_link_libraries(Bear PRIVATE glfw
                                   OpenGL::GL
                                   GLEW::GLEW)
