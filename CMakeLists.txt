cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME GameTrying)
project(${PROJECT_NAME})

set(SOURCES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})