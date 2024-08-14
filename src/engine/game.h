#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include "control/process_events_manager.h"
#include "control/window_manager.h"
#include "control/texture_manager.h"
#include "sprite/sprite.h"
#include "sprite/sprite_group.h"
#include "../game/creature.h"
#include "utils/simple_utils.h"
#include "utils/load.h"
#include "utils/core_statistics_hub.h"
#include "../game/player.h"


class Game {
public:

    Game();
    
    void runMainGameLoop();

    // Camera& getCamera();

    // void resetSong();

    // MusicPlayer musicPlayer;



private:

    void processEvents(std::vector<std::string>);

    Player player;

    std::vector<Bullet> bullet_container;

};

#endif  // GAME_H_