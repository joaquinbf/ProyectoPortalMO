#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/world.h"
#include "../../../include/instructions/delete_body_instruction.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/launcher/launcher.h"
#include "../../../include/bodies/receiver/receiver.h"
#include <cstdint>

Bullet::Bullet(
    World *world,
    float x, float y, DIRECTION direction):
    Body(world, ENTITY::BULLET),
    direction(direction) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_dynamicBody;
    b2bodydef.position.Set(x, y);
    b2bodydef.userData = (void *) this;
    b2bodydef.awake = true;
    b2bodydef.bullet = true;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(this->WIDTH/2, this->HEIGHT/2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);

    this->setVelocity();
}

Bullet::~Bullet() {
    if (this->b2body != 0) {
        this->world->getB2World()->DestroyBody(this->b2body);
    }
}

float Bullet::getVelocity() const {
    return VELOCITY;
}


Update Bullet::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        this->direction);
    return update;
}

void Bullet::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Bullet::handleBeginContactWith(Block *block, b2Contact *contact) {
    this->world->addInstruction(new DeleteBodyInstruction(this));
}

void Bullet::handleBeginContactWith(Launcher *launcher, b2Contact *contact) {
    this->world->addInstruction(new DeleteBodyInstruction(this));
}

void Bullet::handleBeginContactWith(Receiver *receiver, b2Contact *contact) {
    receiver->turnOn();
    this->world->addInstruction(new DeleteBodyInstruction(this));
}

void Bullet::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Bullet::setVelocity() {
    // contrarresto g
    this->b2body->ApplyForceToCenter(b2Vec2(0, 9.8), true);

    switch (this->direction) {
        case DIRECTION::RIGHT_DIRECTION:
            this->b2body->SetLinearVelocity(b2Vec2(VELOCITY, 0));
            break;
        case DIRECTION::LEFT_DIRECTION:
            this->b2body->SetLinearVelocity(b2Vec2(-VELOCITY, 0));
            break;
        case DIRECTION::UP_DIRECTION:
            this->b2body->SetLinearVelocity(b2Vec2(0, VELOCITY));
            break;
        case DIRECTION::DOWN_DIRECTION:
            this->b2body->SetLinearVelocity(b2Vec2(0, -VELOCITY));
            break;
    }
}

void Bullet::applyStateAction() {
    this->setVelocity();
}
