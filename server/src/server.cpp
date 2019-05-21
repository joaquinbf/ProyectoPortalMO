#include "../include/server.h"
#include "../include/accepter.h"
#include "../include/world.h"
#include <iostream>

int Server::main() {
    World world;
    world.start();

    Accepter accepter(&world);
    accepter.start();

    const char QUIT = 'q';
    while (std::cin.get() != QUIT) {
    }

    accepter.join();
    world.join();
    
    return 0;
}
