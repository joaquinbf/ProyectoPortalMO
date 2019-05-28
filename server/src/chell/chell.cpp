#include "../../include/chell/chell.h"


Chell::Chell(b2World *b2world, float x, float y):
    idle_state(this),
    running_state(this),
    jumping_state(this) {
    this->body_number++;
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
    this->changeStateToIdle();
}

Chell::~Chell() {
}

void Chell::left() {
    this->state->left();
}

void Chell::right() {
    this->state->right();
}

void Chell::up() {
    this->state->up();
}

void Chell::stopLeft() {
    this->state->stopLeft();
}

void Chell::stopRight() {
    this->state->stopRight();
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

void Chell::applyLinearImpulseStopLeft() {
    // TODO: mejorar usando impulsos
    b2Vec2 vel = this->b2body->GetLinearVelocity();
    if (vel.x < 0) {
        vel.x = 0;
        this->b2body->SetLinearVelocity(vel);
    }
}

void Chell::applyLinearImpulseStopRight() {
    // TODO: mejorar usando impulsos
    b2Vec2 vel = this->b2body->GetLinearVelocity();
    if (vel.x > 0) {
        vel.x = 0;
        this->b2body->SetLinearVelocity(vel);
    }
}

void Chell::changeStateToIdle() {
    this->state = &this->idle_state;
}

void Chell::changeStateToRunning() {
    this->state = &this->running_state;
}

void Chell::changeStateToJumping() {
    this->state = &this->jumping_state;
}

Update Chell::getCreateUpdate() {
    Update update(
        COMMAND::CREATE_COMMAND,
        ENTITY::CHELL,
        this->body_number,
        STATUS::CHELL_IDLE,
        (uint32_t)this->b2body->GetPosition().x,
        (uint32_t)this->b2body->GetPosition().y,
        0
    );
    return update;
}

Update Chell::getUpdate() {
    Update update;
    return update;
}
