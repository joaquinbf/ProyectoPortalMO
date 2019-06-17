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
#include "../../../include/bodies/launcher/launcher.h"
#include "../../../include/bodies/receiver/receiver.h"
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
#include "../../../include/bodies/cake/cake.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2DistanceJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2PulleyJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2WeldJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2MouseJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2RopeJoint.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/Joints/b2FrictionJoint.h"
#include "../../../include/instructions/grab_rock_instruction.h"
#include "../../../include/instructions/release_rock_instruction.h"


Chell::Chell(World *world, float x, float y):
    Body(world, ENTITY::CHELL),
    is_facing_right(true),
    idle_state(this),
    running_state(this),
    jumping_state(this),
    dead_state(this),
    state(&this->idle_state),
    portal_gun(this),
    is_in_grabbing_mode(false),
    joint(nullptr) {
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
}

Chell::~Chell() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

bool Chell::isGrabbingARock() const {
    return this->joint != nullptr;
}

void Chell::releaseRock() {
    if (this->isGrabbingARock()) {
        this->world->getB2World()->DestroyJoint(this->joint);
        this->joint = nullptr;
    }
}


void Chell::grabRock(Rock *rock) {
    if (!this->isGrabbingARock()) {
        b2DistanceJointDef jointdef;
        jointdef.length = 0;
        jointdef.frequencyHz = 1.0;
        jointdef.dampingRatio = 0.5;
        jointdef.Initialize(this->getB2Body(), rock->getB2Body(),
                            this->getPosition(), rock->getPosition());
        this->joint = this->world->getB2World()->CreateJoint(&jointdef);
        rock->beGrabbedBy(this);
    }
}

bool Chell::isInGrabbingMode() const {
    return this->is_in_grabbing_mode;
}

void Chell::enterGrabbingMode() {
    this->is_in_grabbing_mode = true;
}

void Chell::exitGrabbingMode() {
    this->is_in_grabbing_mode = false;
}

PortalGun *Chell::getPortalGun() {
    return &this->portal_gun;
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

void Chell::pressGrab() {
    if (this->isGrabbingARock()) {
        this->world->addInstruction(new ReleaseRockInstruction(this));
    } else {
        this->enterGrabbingMode();
    }
}

void Chell::releaseGrab() {
    if (this->isInGrabbingMode()) {
        this->exitGrabbingMode();
    }
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

void Chell::handleBeginContactWith(Cake *cake, b2Contact *contact) {
    cake->insertChellInSet(this);
}

void Chell::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    this->land();
}

void Chell::handleBeginContactWith(Launcher *launcher, b2Contact *contact) {
    this->land();
}

void Chell::handleBeginContactWith(Portal *portal, b2Contact *contact) {
    portal->teleportToOppositePortal(this);
}

void Chell::handleBeginContactWith(Receiver *receiver, b2Contact *contact) {
    this->land();
}

void Chell::handleBeginContactWith(Rock *rock, b2Contact *contact) {
    if (this->isInGrabbingMode() && !rock->isGrabbed()) {
        this->world->addInstruction(new GrabRockInstruction(this, rock));
        this->exitGrabbingMode();
    }
}

void Chell::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Chell::handleEndContactWith(Button *button, b2Contact *contact) {
    button->release();
}
