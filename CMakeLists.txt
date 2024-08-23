cmake_minimum_required(VERSION 3.20)
project(sheldr)

# set(CMAKE_CXX_COMPILER "/usr/bin/clang++-18")

set(CMAKE_CXX_STANDARD 17)


find_package(SFML COMPONENTS graphics audio REQUIRED)  

set(SOURCES 

    src/main.cpp 


    src/engine/control/process_events_manager.cpp 
    src/engine/control/process_events_manager.h 
    src/engine/control/window_manager.cpp 
    src/engine/control/window_manager.h
    src/engine/control/texture_manager.cpp 
    src/engine/control/texture_manager.h 
    src/engine/control/audio_manager.cpp 
    src/engine/control/audio_manager.h
    src/engine/control/state_manager.cpp 
    src/engine/control/state_manager.h 

    src/engine/collider/collider.cpp 
    src/engine/collider/collider.h 
    src/engine/collider/rectangle_collider.cpp 
    src/engine/collider/rectangle_collider.h 
    src/engine/collider/circle_collider.cpp 
    src/engine/collider/circle_collider.h 

    src/engine/sprite/sprite.cpp 
    src/engine/sprite/sprite.h 
    src/engine/sprite/sprite_group.cpp 
    src/engine/sprite/sprite_group.h 

    src/engine/utils/simple_utils.cpp 
    src/engine/utils/simple_utils.h 
    src/engine/utils/load.cpp 
    src/engine/utils/load.h 
    src/engine/utils/core_statistics_hub.cpp 
    src/engine/utils/core_statistics_hub.h 
    src/engine/utils/math_utils.cpp 
    src/engine/utils/math_utils.h 
    
    
    src/game/game.cpp 
    src/game/game.h 
    src/game/creature.cpp 
    src/game/creature.h 
    src/game/player.cpp 
    src/game/player.h 
    src/game/bullet.cpp 
    src/game/bullet.h 
    src/game/building.cpp 
    src/game/building.h 

    src/game/states/playing_state.cpp 
    src/game/states/playing_state.h 
    )

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
    

add_executable(testApp ${SOURCES})

target_link_libraries(testApp sfml-graphics sfml-audio)
