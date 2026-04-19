cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME GameTrying)
project(${PROJECT_NAME})

find_package(raylib REQUIRED)
find_package(box2d REQUIRED)

set(SOURCES src/main.cpp
    src/timer.cpp
    src/player.cpp 
    src/utils.cpp 
    src/instance_manager.cpp
    src/actor.cpp
    vendor/source/nanosvg.cpp)
add_executable(${PROJECT_NAME} ${SOURCES}
    src/plugin.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib box2d)
target_include_directories(${PROJECT_NAME} PRIVATE vendor/include)

add_definitions(-DPROJECT_ROOT="${CMAKE_SOURCE_DIR}")