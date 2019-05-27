#include "../../include/chell/chell.h"

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
    this->state = new IdleState();
}

void Chell::keyLeft() {
    this->state->keyLeft();
}
