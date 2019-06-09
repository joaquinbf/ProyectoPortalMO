#include "../../include/bodies/body.h"
#include "../../include/bodies/acid/acid.h"
#include "../../include/bodies/chell/chell.h"
#include "../../include/bodies/block/block.h"
#include "../../include/bodies/gate/gate.h"
#include "../../include/bodies/button/button.h"
#include "../../include/bodies/launcher/launcher.h"
#include "../../include/bodies/rock/rock.h"
#include "../../include/bodies/bullet/bullet.h"
#include "../../include/world.h"
#include <cstdint>

Body::Body(World *world, ENTITY entity):
    BODY_ID(world->getBodyCount()),
    world(world),
    entity(entity) {
    world->insertNewBody(this);
}

Body::~Body() {
}

float Body::getPosX() const {
    return this->b2body->GetPosition().x;
}

float Body::getPosY() const {
    return this->b2body->GetPosition().y;
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

void Body::handleBeginContactWith(Block *block) {
}

void Body::handleBeginContactWith(Bullet *bullet) {
}

void Body::handleBeginContactWith(Button *button) {
}

void Body::handleBeginContactWith(Chell *chell) {
}

void Body::handleBeginContactWith(Gate *gate) {
}

void Body::handleBeginContactWith(Launcher *launcher) {
}

void Body::handleBeginContactWith(Rock *rock) {
}

void Body::handleEndContactWith(Acid *acid) {
}

void Body::handleEndContactWith(Block *block) {
}

void Body::handleEndContactWith(Button *button) {
}

void Body::handleEndContactWith(Bullet *bullet) {
}

void Body::handleEndContactWith(Chell *chell) {
}

void Body::handleEndContactWith(Gate *gate) {
}

void Body::handleEndContactWith(Launcher *launcher) {
}

void Body::handleEndContactWith(Rock *rock) {
}
