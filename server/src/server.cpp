#include "../include/server.h"
#include <iostream>

int Server::main() {
    Accepter accepter;
    accepter.start();

    const char QUIT = 'q';
    while (std::cin.get() != QUIT) {
    }

    accepter.join();

    return 0;
}
