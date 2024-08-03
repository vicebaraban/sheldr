cmake_minimum_required(VERSION 3.20)
project(sheldr)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++-18")

set(CMAKE_CXX_STANDARD 17)


find_package(SFML COMPONENTS graphics audio REQUIRED)  

set(SOURCES 

    src/main.cpp 

    src/engine/game.cpp
    src/engine/game.h 

    src/engine/control/process_events_manager.cpp 
    src/engine/control/process_events_manager.h 
    src/engine/control/window_manager.cpp 
    src/engine/control/window_manager.h
    src/engine/control/texture_manager.cpp 
    src/engine/control/texture_manager.h 
    src/engine/control/audio_manager.cpp 
    src/engine/control/audio_manager.h

    src/engine/sprite/sprite.cpp 
    src/engine/sprite/sprite.h 
    src/engine/sprite/sprite_group.cpp 
    src/engine/sprite/sprite_group.h
    
    src/game/creature.cpp 
    src/game/creature.h
    )

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
    

add_executable(testApp ${SOURCES})

target_link_libraries(testApp sfml-graphics sfml-audio)
