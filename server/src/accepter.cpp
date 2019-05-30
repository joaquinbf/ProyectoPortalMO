#include "../include/accepter.h"
#include "../../common/include/exceptions.h"
#include <vector>

Accepter::Accepter() {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
}

void Accepter::run() {
    Match match;
    match.buildLevelOne();

    std::vector<Player *> players;
    try {
        for (int i = 0; i < 2; i++) {
            Socket peer = this->socket.accept();
            std::cout << "despues de accept" << std::endl;
            Player *player = new Player(std::move(peer), &match);
            std::cout << "despues de new player" << std::endl;
            players.push_back(player);
            player->start();
        }

        match.start();
        std::cout << "despues match start" << std::endl;
        while (this->keep_running) {
            std::cout << "WHILE: accepter" << std::endl;
        }
        match.stop();
        std::cout << "despues match stop" << std::endl;
        match.join();
        std::cout << "despues match join" << std::endl;

        for (Player *player: players) {
            try {
                player->stop();
            } catch (const ConnectionErrorException &e) {
            }
            std::cout << "despues player.stop()" << std::endl;
            player->join();
            std::cout << "despues player.join()" << std::endl;
            delete player;
            std::cout << "despues delete" << std::endl;
        }
    } catch (const ConnectionErrorException &e) {
    }


    std::cout << "FIN RUN accepter" << std::endl;
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.close();
}
