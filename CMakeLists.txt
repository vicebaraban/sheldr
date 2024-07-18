cmake_minimum_required(VERSION 3.20)
project(sheldr)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++-18")

set(CMAKE_CXX_STANDARD 17)


find_package(SFML COMPONENTS graphics REQUIRED)  

set(SRC_FILES 
    src/main.cpp 
    src/engine/game.cpp
    )
set(HEADER_FILES 
    include/engine/game.h
    )

add_executable(testApp ${SRC_FILES} ${HEADER_FILES})

target_link_libraries(testApp sfml-graphics)
