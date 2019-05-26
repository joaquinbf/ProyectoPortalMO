#include "../include/chell.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

Chell::Chell(b2World *b2world, float x, float y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
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

    this->looking_right = true;
    this->state = new IdleState(this);
}

void Chell::runLeft() {
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-10, 0), true);
}

void Chell::runRight() {
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(10, 0), true);
}

void Chell::jump() {
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(0, -10), true);
}

void Chell::newState(ChellState *new_state) {
    ChellState *old_state = this->state;
    this->state = new_state;
    delete old_state;
}
