#include "../include/world.h"
#include <iostream>

World::World():
    keep_running(true),
    b2world(b2Vec2(0.0, 9.8)) {
}

void World::run() {
    while (this->keep_running) {
    }
}

void World::stop() {
    this->keep_running = false;
}

void World::addPlayer(Player *player) {
    this->players.emplace_back(player);
}

void World::createWorldOne() {
    Chell *chell = new Chell(&this->b2world, 0, 20);
    this->bodies.emplace_back(chell);

    for (Player *player: this->players) {
        player->sendBodies(this->bodies);
    }
}
