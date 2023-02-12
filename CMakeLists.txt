#version 3.11 or later of Cmake needed for installing GoogleTest
cmake_minimum_required(VERSION 3.14)

project(RTLS_project)

add_subdirectory(components)
add_subdirectory(test)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE components)

target_compile_features(main PUBLIC cxx_std_20)