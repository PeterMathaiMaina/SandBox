# CMakeLists.txt in the root directory

cmake_minimum_required(VERSION 3.10)

# Project name
project(MyGameProject)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Add the subdirectories for both engine and game
add_subdirectory(Bear)
add_subdirectory(SandBox)

