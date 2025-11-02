# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Name your project
project(raytrace)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your executable target
add_executable(raytrace src/main.cpp)
