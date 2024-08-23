#ifndef GAME_H_
#define GAME_H_


#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Window.hpp>
#include <stack>
#include <vector>
#include "../engine/control/process_events_manager.h"
#include "../engine/control/window_manager.h"
#include "../engine/control/texture_manager.h"
#include "../engine/sprite/sprite.h"
#include "../engine/sprite/sprite_group.h"
#include "creature.h"
#include "../engine/utils/simple_utils.h"
#include "../engine/utils/load.h"
#include "../engine/utils/core_statistics_hub.h"
#include "player.h"
#include "../engine/control/state_manager.h"
#include "states/playing_state.h"


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