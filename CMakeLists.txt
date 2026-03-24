cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME GameTrying)
project(${PROJECT_NAME})

find_package(raylib REQUIRED)

set(SOURCES src/main.cpp src/timer.cpp src/player.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)