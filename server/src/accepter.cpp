#include "../include/accepter.h"
#include "../../common/include/exceptions.h"
#include "../../common/include/socket.h"
#include "../include/player.h"
#include "../include/world.h"
#include <vector>


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
            Player *new_player = new Player(peer, this->world);
            new_player->start();
            players.emplace_back(new_player);
        }
    } catch (const ConnectionErrorException &e) {
    }

    for (Player *player: players) {
        player->join();
        delete player;
    }
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.shutdown('f');
    this->socket.close();
}
