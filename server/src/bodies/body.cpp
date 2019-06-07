#include "../../include/bodies/body.h"

Body::Body(uint32_t body_id, ENTITY entity):
    BODY_ID(body_id),
    entity(entity) {
}

Body::~Body() {
}

uint32_t Body::getBodyId() const {
    return this->BODY_ID;
}

void Body::awake() {
    this->b2body->SetAwake(true);
}

void Body::putToSleep() {
    this->b2body->SetAwake(false);
}

void Body::applyStateAction() {
}

void Body::handleBeginContactWith(Chell *chell) {
}

void Body::handleBeginContactWith(Block *block) {
}

void Body::handleBeginContactWith(Button *button) {
}

void Body::handleBeginContactWith(Gate *gate) {
}

void Body::handleBeginContactWith(Rock *rock) {
}

void Body::handleEndContactWith(Chell *chell) {
}

void Body::handleEndContactWith(Block *block) {
}

void Body::handleEndContactWith(Button *button) {
}

void Body::handleEndContactWith(Gate *gate) {
}

void Body::handleEndContactWith(Rock *rock) {
}

bool Body::isAwake() const {
    return this->b2body->IsAwake();
}
