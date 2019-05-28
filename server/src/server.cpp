#include "../include/server.h"

int Server::main() {

    Accepter accepter;
    accepter.start();

    const char QUIT = 'q';
    while (std::cin.get() != QUIT) {
    }

    accepter.stop();
    accepter.join();

    return 0;
}
