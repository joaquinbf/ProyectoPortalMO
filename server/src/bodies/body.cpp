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

void Body::applyStateAction() {
}

void Body::handleBeginContactBeHandledBy(Chell *chell) {
}

void Body::handleBeginContactBeHandledBy(Block *block) {
}

void Body::handleBeginContactBeHandledBy(Button *button) {
}

void Body::handleBeginContactBeHandledBy(Gate *gate) {
}

void Body::handleBeginContactBeHandledBy(Rock *rock) {
}

void Body::handleEndContactBeHandledBy(Chell *chell) {
}

void Body::handleEndContactBeHandledBy(Block *block) {
}

void Body::handleEndContactBeHandledBy(Button *button) {
}

void Body::handleEndContactBeHandledBy(Gate *gate) {
}

void Body::handleEndContactBeHandledBy(Rock *rock) {
}

bool Body::isAwake() const {
    return this->b2body->IsAwake();
}
