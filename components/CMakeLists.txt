#version 3.11 or later of Cmake needed for installing GoogleTest
cmake_minimum_required(VERSION 3.14)

project(components)

add_library(components 
src/Tag.cpp 
src/Anchor.cpp 
src/Gateway.cpp
src/StateMachine.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)
