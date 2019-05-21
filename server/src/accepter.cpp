#include "../include/accepter.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/socket.h"
#include "../include/player.h"
#include "../include/world.h"
#include <vector>
#include <iostream>

Accepter::Accepter(World *world) {
    this->socket.bindAndListen(PORT);
    this->keep_running = true;
    this->world = world;
}

void Accepter::run() {
    this->keep_running = true;
    std::vector<Player *> players;

    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();
            std::cout << "acepto un cliente " << std::endl;
            Player *new_player = new Player(peer);
            new_player->start();
            players.emplace_back(new_player);
            this->world->addPlayer(new_player);
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
    this->socket.close();
}
