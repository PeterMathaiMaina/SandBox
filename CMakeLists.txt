 cmake_minimum_required(VERSION 3.10)
project(GameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)  # Global PIC flag

# Dependencies
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

# Add subdirectories
add_subdirectory(imgui)
add_subdirectory(Bear)                      
add_subdirectory(SandBox)
add_subdirectory(glm)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
