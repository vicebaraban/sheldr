#include "game/game.h"


int main() {
    try {

        Game app;
        app.run();
        return EXIT_SUCCESS;

    }
    catch(std::exception& e) {

        return EXIT_FAILURE;
        
    }
}