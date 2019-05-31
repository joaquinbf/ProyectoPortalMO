#include "../include/world_core.h"

#include "../include/bodies/body.h"

WorldCore::WorldCore(b2World *b2world):
    b2world(b2world) {
}

WorldCore::~WorldCore() {
    this->deleteBodies();
}

void WorldCore::deleteBodies() {
    for (Body *body: this->bodies) {
        delete body;
    }
}
