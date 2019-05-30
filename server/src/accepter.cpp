#include "../include/accepter.h"
#include "../../common/include/exceptions.h"
#include <vector>

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

void Accepter::run() {
    int MAX_PLAYERS = 1;
    Match match;
    std::vector<Player *> players;

    this->keep_running = true;
    try {
        for (int i = 0; i < MAX_PLAYERS; i++) {
            std::cout << "antes de socket.accept()" << std::endl;
            Socket peer = this->socket.accept();
            std::cout << "despues de socket.accept()" << std::endl;

            Player *player = new Player(std::move(peer), &match);
            players.push_back(player);
            player->start();
        }
        std::cout << "antes de match.start() en accepter.cpp" << std::endl;
        match.start();
        // TODO: Mejorar
        while (!players.at(0)->isFinished()) {
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
