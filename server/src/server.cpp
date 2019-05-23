#include "../include/server.h"
#include "../include/accepter.h"
#include "../include/world.h"
#include <iostream>

int Server::main() {
    World world;
    world.start();
    world.createWorldOne();

    Accepter accepter(&world);
    accepter.start();

    const char QUIT = 'q';
    while (std::cin.get() != QUIT) {
    }

    accepter.stop();
    accepter.join();
    world.stop();
    world.join();

    return 0;
}
