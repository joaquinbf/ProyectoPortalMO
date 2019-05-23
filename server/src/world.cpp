#include "../include/world.h"
#include <iostream>

World::World():
    keep_running(true),
    b2world(b2Vec2(0.0, 9.8)) {
}

void World::run() {
    while (this->keep_running) {
        this->addInputsFromAllPlayers();
    }
}

void World::stop() {
    this->keep_running = false;
}

void World::addPlayer(Player *player) {
    this->players.emplace_back(player);
}

void World::createWorldOne() {
    std::cout << "create world one" << std::endl;
    Chell *chell = new Chell(&this->b2world, 0, 20);
    this->bodies.emplace_back(chell);
}

void World::sendBodiesToPlayer(Player *player) {
    std::cout << "send bodies to player" << std::endl;
    player->sendBodies(this->bodies);
}

void World::addInputsFromAllPlayers() {
    for (Player *player: this->players) {
        this->addInputsFrom(player);
    }
}

void World::addInputsFrom(Player *player) {
    ProtectedQueue<Action> *queue = player->getInputReceiver()->getQueue();
    Action action;

    while (queue->try_pop(action)) {
        switch (action.getAction()) {
            case ACTION::RUN_LEFT:
                std::cout << "run left" << std::endl;
                break;
            case ACTION::RUN_RIGHT:
                std::cout << "run right" << std::endl;
                break;
            default:
                std::cout << "action no reconocida!" << std::endl;
                break;
        }
    }
}
