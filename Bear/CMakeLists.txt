# /GameEngine/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Bear)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "/home/kelly/vcpkg-master/scripts/buildsystems/vcpkg.cmake" CACHE STRING "" FORCE)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(assimp REQUIRED)
find_package(glm REQUIRED)
set(SPDLOG_BUILD_SHARED ON)
set(SPDLOG_BUILD_STATIC OFF)


#find_package(spdlog CONFIG  REQUIRED)


include_directories(${GLM_INCLUDE_DIRS})

find_package(OpenGL REQUIRED)
# Set policy to prefer GLVND (Modern OpenGL)
cmake_policy(SET CMP0072 NEW)

add_library(Bear SHARED
    scr/Utils/Log.cpp
    scr/Engine.cpp
    Include/Engine.h
    scr/Renderer/GraphicsContext.cpp
    scr/Platforms/Linux/Lin_Windows.cpp
    scr/Window/Window.cpp
)
add_subdirectory(vendor/spdlog)

target_include_directories(Bear
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/Include/Events
        ${GLFW_INCLUDE_DIRS}
)


target_link_libraries(Bear
    PUBLIC
        spdlog::spdlog   # <-- THIS is what propagates spdlog headers
        glfw
        OpenGL::GL
        GLEW::GLEW
)
