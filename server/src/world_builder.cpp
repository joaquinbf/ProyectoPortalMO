#include "../include/world_builder.h"
#include "../include/world.h"
#include "../include/bodies/body.h"
#include "../include/bodies/block/block.h"
#include <iostream>

WorldBuilder::WorldBuilder(World *world):
    world(world),
    body_id_count(0) {
}

void WorldBuilder::createSquareMetalBlock(float x, float y) {
    Block *block = new Block(
        this->world, x, y,
        ORIENTATION::ORIENTATION_0,
        SHAPE::SQUARE, MATERIAL::METAL);
    delete block;
}

void WorldBuilder::destroyAllBodies() {
    for (Body *body: this->all_bodies) {
        delete body;
    }
    this->all_bodies.clear();
}
