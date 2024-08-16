#ifndef GAME_H_
#define GAME_H_


#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Window.hpp>
#include <stack>
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
#include "control/state_manager.h"
#include "../game/states/playing_state.h"


class Game {

public:

    Game();
    
    void run();

    // Camera& getCamera();

    // void resetSong();

    // MusicPlayer musicPlayer;



private:

    std::stack<State *> states;

    StateData state_data;
    
    // Initialization
    void initWindow();
    void initAssets();
    void initVariables();
    void initStates();
    void initStateData();


    void updateSystem();
    void updateState();

    void renderWindow();

    void renderSystemInfo();


    utils::StatisticsHub statistics_text;

    unsigned int fps;

    sf::Clock clock;
    sf::Time dt;
    sf::Time time_per_frame;

};

#endif  // GAME_H_