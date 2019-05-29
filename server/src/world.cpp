#include "../include/world.h"
#include "../include/chell/chell.h"

World::World(b2World *b2world):
    b2world(b2world) {
}

Chell *World::createChell() {
    return 0;
}
