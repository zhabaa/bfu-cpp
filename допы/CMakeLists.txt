cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME cpp)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDART_REQUIRED True)

add_executable(${PROJECT_NAME} 2.cpp)
