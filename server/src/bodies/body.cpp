#include "../../include/bodies/body.h"
#include "../../include/bodies/acid/acid.h"
#include "../../include/bodies/chell/chell.h"
#include "../../include/bodies/block/block.h"
#include "../../include/bodies/gate/gate.h"
#include "../../include/bodies/button/button.h"
#include "../../include/bodies/launcher/launcher.h"
#include "../../include/bodies/rock/rock.h"
#include "../../include/bodies/bullet/bullet.h"
#include "../../include/bodies/receiver/receiver.h"
#include "../../include/bodies/portal/portal.h"
#include "../../include/world.h"
#include <cstdint>

Body::Body(World *world, ENTITY entity):
    BODY_ID(world->getBodyCount()),
    world(world),
    entity(entity) {
    world->incBodyCount();
    world->addToBodies(this);
}

Body::~Body() {
}

bool Body::canOpenPortalOnSurface() const {
    return false;
}

float Body::getAngle() const {
    return this->b2body->GetAngle();
}

void Body::setLinearVelocity(b2Vec2 v) {
    this->b2body->SetLinearVelocity(v);
}

b2Vec2 Body::getLinearVelocity() const {
    return this->b2body->GetLinearVelocity();
}

bool Body::isActive() const {
    return this->b2body->IsActive();
}

void Body::activate() {
    this->b2body->SetActive(true);
}

void Body::desactivate() {
    this->b2body->SetActive(false);
}

void Body::setTransform(b2Vec2 pos, float angle) {
    this->b2body->SetTransform(pos, angle);
}


World *Body::getWorld() const {
    return this->world;
}


void Body::setPosition(b2Vec2 pos) {
    this->b2body->SetTransform(pos, 0);
}

b2Vec2 Body::getPosition() const {
    return this->b2body->GetPosition();
}


float Body::getMagnitudOfVelocity() const {
    return this->b2body->GetLinearVelocity().Length();
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

void Body::handleBeginContactWith(Acid *acid, b2Contact *contact) {
}

void Body::handleBeginContactWith(Block *block, b2Contact *contact) {
}

void Body::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
}

void Body::handleBeginContactWith(Button *button, b2Contact *contact) {
}

void Body::handleBeginContactWith(Chell *chell, b2Contact *contact) {
}

void Body::handleBeginContactWith(Gate *gate, b2Contact *contact) {
}

void Body::handleBeginContactWith(Launcher *launcher, b2Contact *contact) {
}

void Body::handleBeginContactWith(Portal *portal, b2Contact *contact) {
}

void Body::handleBeginContactWith(Receiver *receiver, b2Contact *contact) {
}

void Body::handleBeginContactWith(Rock *rock, b2Contact *contact) {
}

void Body::handleEndContactWith(Acid *acid, b2Contact *contact) {
}

void Body::handleEndContactWith(Block *block, b2Contact *contact) {
}

void Body::handleEndContactWith(Button *button, b2Contact *contact) {
}

void Body::handleEndContactWith(Bullet *bullet, b2Contact *contact) {
}

void Body::handleEndContactWith(Chell *chell, b2Contact *contact) {
}

void Body::handleEndContactWith(Gate *gate, b2Contact *contact) {
}

void Body::handleEndContactWith(Launcher *launcher, b2Contact *contact) {
}

void Body::handleEndContactWith(Portal *portal, b2Contact *contact) {
}

void Body::handleEndContactWith(Receiver *receiver, b2Contact *contact) {
}

void Body::handleEndContactWith(Rock *rock, b2Contact *contact) {
}
