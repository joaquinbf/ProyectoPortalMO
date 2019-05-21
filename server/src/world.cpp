#include "../include/world.h"
#include <iostream>

World::World():
    keep_running(true),
    b2world(b2Vec2(0.0, 9.8)) {
}

void World::run() {
    for (Player *player: this->players) {
        ProtectedQueue<Action> *queue = player->getInputReceiver()->getQueue();
        Action action;
        if (queue->try_pop(action)) {
            std::cout << "world: action recibida  = "
                      << action.getAction()
                      << std::endl;
        }
    }
}

void World::stop() {
    this->keep_running = false;
}

void World::addPlayer(Player *player) {
    this->players.emplace_back(player);
}
