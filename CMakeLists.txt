cmake_minimum_required(VERSION 3.10)

project(spacey C)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} 
    ../src/draw.c 
    ../src/game.c 
    ../src/input.c 
    ../src/main.c)

target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2_image::SDL2_image)