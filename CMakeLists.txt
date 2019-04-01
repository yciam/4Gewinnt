cmake_minimum_required(VERSION 3.12)
project(4gewinnt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${4gewinnt_SOURCE_DIR}/cmake")

include_directories(.)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(4gewinnt main.cpp src/Game.cpp src/Game.h src/State.h src/Board.cpp src/Board.h src/utilities.cpp src/utilities.h)


include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(4gewinnt ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})