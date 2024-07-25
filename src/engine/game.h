#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include "control/process_events_manager.h"
#include "control/window_manager.h"
#include "control/texture_manager.h"
#include "sprite/sprite.h"
#include "sprite/sprite_group.h"


class Game {
public:

    Game();
    
    void runMainGameLoop();

    // Camera& getCamera();

    // void resetSong();

    // MusicPlayer musicPlayer;



private:

};

#endif  // GAME_H_