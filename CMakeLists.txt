# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Name your project
project(raytrace)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your executable target
add_executable(raytrace
    src/main.cpp
    src/vec3.cpp
    src/color.cpp
    src/ray.cpp
    src/actor.cpp
    src/actor_list.cpp
    src/sphere.cpp
    src/interval.cpp
    src/camera.cpp
    src/material.cpp
)

# Tell the compiler where to find headers
target_include_directories(raytrace PUBLIC inc)
