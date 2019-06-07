
#include "../../../include/bodies/chell/chell.h"

#include "../../../include/bodies/body.h"
#include "../../../include/bodies/chell/chell_state.h"
#include "../../../include/bodies/chell/idle_state.h"
#include "../../../include/bodies/chell/running_state.h"
#include "../../../include/bodies/chell/jumping_state.h"
#include "../../../include/bodies/button/button.h"
#include "../../../../common/include/key.h"
#include "../../../../common/include/keypad.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include <iostream>
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/rock/rock.h"


Chell::Chell(uint32_t body_id, b2World *b2world, float x, float y):
    Body(body_id, ENTITY::CHELL),
    is_facing_right(true),
    idle_state(this),
    running_state(this),
    jumping_state(this),
    state(&this->idle_state) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = this->ANGLE;
    bodyDef.userData = (void *) this;
    bodyDef.fixedRotation = true;

    this->b2body = b2world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(this->HALF_WIDTH, this->HALF_HEIGHT);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = this->DENSITY;
    boxFixtureDef.userData = (void *) this;

    b2Fixture* b2fixture = this->b2body->CreateFixture(&boxFixtureDef);
    b2fixture->SetUserData((void *)this);
}

bool Chell::isFacingRight() {
    return this->is_facing_right;
}

void Chell::faceRight() {
    this->is_facing_right = true;
}

void Chell::faceLeft() {
    this->is_facing_right = false;
}

void Chell::faceOppositeDirection() {
    this->is_facing_right = !this->is_facing_right;
}

Update Chell::createUpdate(COMMAND command) const {
    Update update(
        command,
        ENTITY::CHELL,
        this->BODY_ID,
        this->state->getStatus(),
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        this->is_facing_right? 1 : 0);
    return update;
}

void Chell::pressLeft() {
    this->keypad.press(KEY::LEFT_KEY);
    this->state->pressLeft();
}

void Chell::releaseLeft() {
    this->keypad.release(KEY::LEFT_KEY);
    this->state->releaseLeft();
}

void Chell::pressRight() {
    this->keypad.press(KEY::RIGHT_KEY);
    this->state->pressRight();
}

void Chell::releaseRight() {
    this->keypad.release(KEY::RIGHT_KEY);
    this->state->releaseRight();
}

void Chell::pressUp() {
    this->keypad.press(KEY::UP_KEY);
    this->state->pressUp();
}

void Chell::releaseUp() {
    this->keypad.release(KEY::UP_KEY);
    this->state->releaseUp();
}


void Chell::changeStateToRunning() {
    if (this->isFacingRight()) {
        this->applyLinearImpulseToRight();
    } else {
        this->applyLinearImpulseToLeft();
    }
    this->state = &this->running_state;
}

void Chell::changeStateToIdle() {
    this->state = &this->idle_state;
}

void Chell::changeStateToJumping() {
    this->state = &this->jumping_state;
    this->applyLinearImpulseToUp();
}


void Chell::applyLinearImpulseToLeft() {
    float mass = this->b2body->GetMass();
    float vel = LEFTSPEED;
    float imp = mass * vel;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-imp, 0), true);
}

void Chell::applyLinearImpulseToRight() {
    float mass = this->b2body->GetMass();
    b2Vec2 v = this->b2body->GetLinearVelocity();
    float vel = RIGHTSPEED;
    float imp = mass * vel;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(imp, v.y), true);
}

void Chell::applyLinearImpulseToUp() {
    float mass = this->b2body->GetMass();
    float vel = JUMPSPEED;
    float imp = mass * vel;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(0, imp), true);
}


void Chell::stopLeftMovement() {
    b2Vec2 vel = this->b2body->GetLinearVelocity();
    if (vel.x < 0) {
        vel.x = 0;
        this->b2body->SetLinearVelocity(vel);
    }
}

void Chell::stopRightMovement() {
    b2Vec2 vel = this->b2body->GetLinearVelocity();
    if (vel.x > 0) {
        vel.x = 0;
        this->b2body->SetLinearVelocity(vel);
    }
}

Keypad *Chell::getKeypad() {
    return &this->keypad;
}

void Chell::applyStateAction() {
    this->state->applyStateAction();
}

void Chell::handleBeginContactWith(Body *other_body) {
    other_body->handleBeginContactWith(this);
}

void Chell::handleBeginContactWith(Block *block) {
    this->changeStateToIdle();
}

void Chell::handleBeginContactWith(Button *button) {
    button->press();
    this->changeStateToIdle();
}

void Chell::handleEndContactWith(Body *other_body) {
    other_body->handleEndContactWith(this);
}

void Chell::handleEndContactWith(Button *button) {
    button->release();
    button->notifyStatusChangeToGate();
}
