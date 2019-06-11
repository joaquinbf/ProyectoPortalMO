#include "../../../include/bodies/chell/chell.h"

#include "../../../include/world.h"
#include "../../../include/ray_cast_closest_body_callback.h"
#include "../../../include/bodies/body.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/bodies/chell/chell_state.h"
#include "../../../include/bodies/chell/idle_state.h"
#include "../../../include/bodies/chell/running_state.h"
#include "../../../include/bodies/chell/jumping_state.h"
#include "../../../include/bodies/button/button.h"
#include "../../../../common/include/key.h"
#include "../../../../common/include/keypad.h"
#include "../../../../common/include/types.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/rock/rock.h"
#include "../../../include/bodies/portal/portal.h"
#include <iostream>

Chell::Chell(World *world, float x, float y):
    Body(world, ENTITY::CHELL),
    is_facing_right(true),
    idle_state(this),
    running_state(this),
    jumping_state(this),
    dead_state(this),
    state(&this->idle_state) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = this->ANGLE;
    bodyDef.userData = (void *) this;
    bodyDef.fixedRotation = true;

    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(this->HALF_WIDTH, this->HALF_HEIGHT);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = this->DENSITY;
    boxFixtureDef.userData = (void *) this;
    boxFixtureDef.friction = this->FRICTION;
    boxFixtureDef.restitution = this->RESTITUTION;

    b2Fixture* b2fixture = this->b2body->CreateFixture(&boxFixtureDef);
    b2fixture->SetUserData((void *)this);

    this->portal_one = world->createPortal(1);
    this->portal_two = world->createPortal(2);
    this->portal_one->setPairWith(this->portal_two);
    this->portal_two->setPairWith(this->portal_one);
}

Portal *Chell::getPortalOne() const {
    return this->portal_one;
}

Portal *Chell::getPortalTwo() const {
    return this->portal_two;
}

void Chell::firePortalOne(float x, float y) {
    this->firePortal(this->portal_one, x, y);
}

void Chell::firePortalTwo(float x, float y) {
    this->firePortal(this->portal_two, x, y);
}

void Chell::firePortal(Portal *portal, float x, float y) {
    this->world->addUpdate(portal->createUpdate(COMMAND::DESTROY_COMMAND));
    portal->desactivate();
    b2Vec2 v(x, y);
    RayCastClosestBodyCallback callback;
    this->world->getB2World()->RayCast(
        &callback,
        this->getPosition(),
        RAY_ZOOM * v);

    if (callback.hasHit()) {
        std::cout << "has hit" << std::endl;
        Body *body = callback.getBody();
        body->tryOpenPortal(
            portal,
            callback.getPoint(),
            callback.getNormal());
    }
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

void Chell::changeStateToDead() {
    this->state = &this->dead_state;
}

void Chell::land() {
    this->state->land();
}

void Chell::applyLinearImpulseToLeft() {
    float mass = this->b2body->GetMass();
    float impx = mass * LEFTSPEED;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-impx, 0), true);
}

void Chell::applyLinearImpulseToRight() {
    float mass = this->b2body->GetMass();
    float impx = mass * RIGHTSPEED;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(impx, 0), true);
}

void Chell::applyLinearImpulseToUp() {
    float mass = this->b2body->GetMass();
    b2Vec2 v = this->b2body->GetLinearVelocity();
    float impx = mass * v.x;
    float impy = mass * JUMPSPEED;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(impx, impy), true);
}

void Chell::stopLeftMovement() {
    b2Vec2 v = this->b2body->GetLinearVelocity();
    if (v.x < 0) {
        float mass = this->b2body->GetMass();
        float impx = mass * v.x;
        float impy = mass * v.y;
        this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-impx, impy), true);
    }
}

void Chell::stopRightMovement() {
    b2Vec2 v = this->b2body->GetLinearVelocity();
    if (v.x > 0) {
        float mass = this->b2body->GetMass();
        float impx = mass * v.x;
        float impy = mass * v.y;
        this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-impx, impy), true);
    }
}

Keypad *Chell::getKeypad() {
    return &this->keypad;
}

void Chell::applyStateAction() {
    this->state->applyStateAction();
}

void Chell::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Chell::handleBeginContactWith(Acid *acid, b2Contact *contact) {
    this->changeStateToDead();
}

void Chell::handleBeginContactWith(Block *block, b2Contact *contact) {
    this->land();
}

void Chell::handleBeginContactWith(Button *button, b2Contact *contact) {
    button->press();
    this->land();
}

void Chell::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Chell::handleEndContactWith(Button *button, b2Contact *contact) {
    button->release();
}
