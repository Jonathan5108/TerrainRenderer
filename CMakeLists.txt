cmake_minimum_required(VERSION 3.10)
project(TerrainRenderer)

set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

set(CMAKE_CXX_STANDARD 11)

include_directories(
    include
    C:/MinGW/include
    C:/MinGW/include/GLFW
    C:/MinGW/include/GL
)

link_directories(
    C:/MinGW/lib
)

find_package(OpenGL REQUIRED)

add_executable(TerrainRenderer src/main.cpp src/utils.cpp src/gl_utils.cpp)

target_link_libraries(TerrainRenderer OpenGL::GL GLEW glfw)
