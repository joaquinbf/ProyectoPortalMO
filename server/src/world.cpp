#include "../include/world.h"

World::World():
    keep_running(true),
    b2world(b2Vec2(0.0, 9.8)) {
}

void World::run() {

}

void World::stop() {
    this->keep_running = false;
}
