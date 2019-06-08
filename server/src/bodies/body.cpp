#include "../../include/bodies/body.h"
#include "../../include/bodies/acid/acid.h"
#include "../../include/bodies/chell/chell.h"
#include "../../include/bodies/block/block.h"
#include "../../include/bodies/gate/gate.h"
#include "../../include/bodies/button/button.h"
#include "../../include/bodies/launcher/launcher.h"
#include "../../include/bodies/rock/rock.h"
#include "../../include/world.h"
#include <cstdint>

Body::Body(uint32_t body_id, World *world, ENTITY entity):
    BODY_ID(body_id),
    world(world),
    entity(entity) {
}

Body::~Body() {
    if (this->b2body != 0) {
        this->world->getB2World()->DestroyBody(this->b2body);
    }
}

uint32_t Body::getBodyId() const {
    return this->BODY_ID;
}

bool Body::isAwake() const {
    return this->b2body->IsAwake();
}

void Body::wakeUp() {
    this->b2body->SetAwake(true);
}

void Body::putToSleep() {
    this->b2body->SetAwake(false);
}

float Body::getMass() const {
    return this->b2body->GetMass();
}

void Body::applyStateAction() {
}

void Body::handleBeginContactWith(Acid *acid) {
}

void Body::handleBeginContactWith(Chell *chell) {
}

void Body::handleBeginContactWith(Block *block) {
}

void Body::handleBeginContactWith(Button *button) {
}

void Body::handleBeginContactWith(Gate *gate) {
}

void Body::handleBeginContactWith(Launcher *launcher) {
}

void Body::handleBeginContactWith(Rock *rock) {
}

void Body::handleEndContactWith(Acid *acid) {
}

void Body::handleEndContactWith(Chell *chell) {
}

void Body::handleEndContactWith(Block *block) {
}

void Body::handleEndContactWith(Button *button) {
}

void Body::handleEndContactWith(Gate *gate) {
}

void Body::handleEndContactWith(Launcher *launcher) {
}

void Body::handleEndContactWith(Rock *rock) {
}
