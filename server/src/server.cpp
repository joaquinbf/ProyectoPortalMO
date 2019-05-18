#include "../include/server.h"
#include "../include/stage.h"
#include <iostream>

int Server::main() {
    Stage stage;
    stage.createStageOne();
    stage.start();

    char quit = 'q';
    while (quit != std::cin.get()) {
    }

    stage.stop();
    stage.join();
    return 0;
}
