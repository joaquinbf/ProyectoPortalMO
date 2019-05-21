#include "../include/accepter.h"
#include <vector>

Accepter::Accepter(Socket *socket):
    socket(socket),
    keep_running(true) {
}


void Accepter::run() {
    this->keep_running = true;
    std::vector<Player> players;

    try {

    } catch (const ConnectionErrorException &e) {

    }
}
