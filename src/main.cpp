#include "engine/game.h"


void initialize() {

    WindowManager::get();

}

int main() {
    try {

        initialize();
        Game app;
        app.runMainGameLoop();
        return EXIT_SUCCESS;

    }
    catch(std::exception& e) {

        return EXIT_FAILURE;
        
    }
}