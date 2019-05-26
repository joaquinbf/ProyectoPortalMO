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

    this->current_state = new IdleState(this);
    this->old_state = 0;
}

void Chell::runLeft() {
    this->current_state->runLeft();
    this->deleteOldStateIfChanged();
}

void Chell::runRight() {
}

void Chell::jump() {

}

void Chell::applyLinearImpulseToLeft() {
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-10, 0), true);
}

void Chell::applyLinearImpulseToRight() {
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(10, 0), true);
}

void Chell::applyLinearImpulseUp() {
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(0, -10), true);
}

void Chell::updateCurrentState(ChellState *new_current_state) {
    this->old_state = this->current_state;
    this->current_state = new_current_state;
}

void Chell::setOldState(ChellState *old_state) {
    this->old_state = old_state;
}

void Chell::deleteOldStateIfChanged() {
    if (this->old_state != 0) {
        delete this->old_state;
        this->old_state = 0;
    }
}

void Chell::fillUpdate(Update &update) {
    update.setIdObject(0);
    update.setStatus(this->current_state->getStatus());
    update.setPosX(this->b2body->GetPosition().x);
    update.setPosY(this->b2body->GetPosition().y);
    /* HARDCODEADO, cambiar */
    update.setDirection(1);
}
