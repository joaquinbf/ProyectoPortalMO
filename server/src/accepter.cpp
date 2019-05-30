#include "../include/accepter.h"
#include "../../common/include/exceptions.h"
#include <vector>

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

void Accepter::run() {
    int MAX_PLAYERS = 3;
    Match match;
    std::vector<Player *> players;

    this->keep_running = true;
    try {
        for (int i = 0; i < MAX_PLAYERS; i++) {
            Socket peer = this->socket.accept();
            Player *player = new Player(std::move(peer), &match);
            players.push_back(player);
            player->start();
        }

        match.start();
        // TODO: Mejorar
        while (!players.at(0)->isFinished()
               && !players.at(1)->isFinished()
               && !players.at(2)->isFinished()) {
        }
        match.stop();
        match.join();

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
    this->socket.close();
}
