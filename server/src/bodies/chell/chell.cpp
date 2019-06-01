#include "../../../include/bodies/chell/chell.h"

#include "../../../include/bodies/body.h"
#include "../../../include/bodies/chell/chell_state.h"
#include "../../../include/bodies/chell/idle_state.h"
#include "../../../include/bodies/chell/running_state.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

Chell::Chell(uint32_t body_id, b2World *b2world, float x, float y):
    Body(body_id),
    is_facing_right(true),
    idle_state(this),
    running_state(this),
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

    this->b2body->CreateFixture(&boxFixtureDef);
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
        STATUS::CHELL_IDLE,
        this->b2body->GetPosition().x,
        this->b2body->GetPosition().y,
        this->is_facing_right? 1 : 0);
    return update;
}

Keypad *Chell::getKeypad() {
    return &this->keypad;
}

void Chell::pressLeft() {
    this->keypad.press(KEY::LEFT_KEY);
}

void Chell::releaseLeft() {
    this->keypad.release(KEY::LEFT_KEY);
}
