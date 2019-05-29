#include "../include/accepter.h"
#include "../../common/include/exceptions.h"
#include <vector>

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

void Accepter::run() {
    Match match;
    std::vector<Player *> players;

    this->keep_running = true;
    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();
            Player *player = new Player(std::move(peer), &match);
            player->start();
            players.push_back(player);
        }
    } catch (const ConnectionErrorException &e) {
    }

    for (Player *player: players) {
        player->stop();
        player->join();
        delete player;
    }
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.shutdown('f');
}
