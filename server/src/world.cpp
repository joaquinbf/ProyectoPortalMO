#include "../include/world.h"
#include <iostream>

World::World():
    keep_running(true),
    b2world(b2Vec2(0.0, 9.8)) {
}

void World::run() {

}

void World::stop() {
    this->keep_running = false;
}

void World::addPlayer(Player *player) {
    this->players.emplace_back(player);
}
