#include "../../include/chell/chell.h"

Chell::Chell(b2World *b2world, float x, float y):
    idle_state(this),
    running_state(this),
    jumping_state(this) {
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
    this->changeToIdleState();
}

Chell::~Chell() {
}

void Chell::keyLeft() {
    this->state->keyLeft();
}

void Chell::keyRight() {
    this->state->keyRight();
}

void Chell::keyJump() {
    this->state->keyJump();
}



void Chell::faceLeft() {
    this->is_facing_right = false;
}

void Chell::faceRight(){
    this->is_facing_right = true;
}

void Chell::faceOpposite() {
    this->is_facing_right = !this->is_facing_right;
}

void Chell::applyLinearImpulseLeft() {
    float mass = this->b2body->GetMass();
    float vel = 30;
    float imp = mass * vel;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(-imp, 0), true);
}

void Chell::applyLinearImpulseRight() {
    float mass = this->b2body->GetMass();
    float vel = 30;
    float imp = mass * vel;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(imp, 0), true);
}

void Chell::applyLinearImpulseUp() {
    float mass = this->b2body->GetMass();
    float vel = 30;
    float imp = mass * vel;
    this->b2body->ApplyLinearImpulseToCenter(b2Vec2(0, imp), true);
}

void Chell::changeToIdleState() {
    this->state = &this->idle_state;
}

void Chell::changeToRunningState() {
    this->state = &this->running_state;
}

void Chell::changeToJumpingState() {
    this->state = &this->jumping_state;
}
