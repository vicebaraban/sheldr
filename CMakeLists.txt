cmake_minimum_required(VERSION 3.20)
project(sheldr)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++-18")

set(CMAKE_CXX_STANDARD 17)


find_package(SFML COMPONENTS graphics REQUIRED)


# Подключение заголовков и библиотек LLVM 
include_directories(${LLVM_INCLUDE_DIRS}) 
link_directories(${LLVM_LIBRARY_DIRS})    
add_definitions(${LLVM_DEFINITIONS})      


add_executable(testApp src/main.cpp)

target_link_libraries(testApp sfml-graphics)
