#include "../../include/chell/chell.h"

Chell::Chell():
    b2body(0),
    current_state(new IdleState(this)),
    old_state(0),
    is_facing_right(true) {
}

Chell::Chell(b2World *b2world, float x, float y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = this->ANGLE;
    bodyDef.userData = (void *) this;
    /* evita que el cuerpo gire */
    bodyDef.fixedRotation = true;

    this->b2body = b2world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(this->HALF_WIDTH, this->HALF_HEIGHT);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = this->DENSITY;

    this->b2body->CreateFixture(&boxFixtureDef);

    this->is_facing_right = true;
    ChellState *current_state = new IdleState(this);
    this->current_state = current_state;
    this->old_state = 0;
}

Chell::~Chell() {
    if (this->old_state != 0) {
        delete this->old_state;
    }

    if (this->current_state != 0) {
        delete this->current_state;
    }
}

void Chell::keyLeft() {
    this->current_state->keyLeft();
    this->deleteOldStateIfUpdated();
}

void Chell::deleteOldStateIfUpdated() {
    if (this->old_state != 0) {
        delete this->old_state;
    }
}

void Chell::setCurrentState(ChellState *state) {
    this->current_state = state;
}

void Chell::setOldState(ChellState *state) {
    this->old_state = state;
}

void Chell::faceLeft() {
    this->is_facing_right = false;
}

void Chell::faceRight(){
    this->is_facing_right = true;
}
