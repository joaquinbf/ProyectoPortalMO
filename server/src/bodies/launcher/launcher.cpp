#include "../../../include/bodies/launcher/launcher.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/instructions/create_bullet_instruction.h"
#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"
#include <cstdint>

Launcher::Launcher(
    World *world,
    float x, float y,
    DIRECTION direction):
    Body(world, ENTITY::LAUNCH_BLOCK),
    direction(direction),
    counter(200) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.position.Set(x, y);
    b2bodydef.userData = (void *) this;
    b2bodydef.awake = false;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(this->WIDTH / 2, this->HEIGHT / 2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
}

Update Launcher::createUpdate(COMMAND command) const {
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

void Launcher::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Launcher::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    this->world->addBodyForDeletion(bullet);
}

void Launcher::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Launcher::applyStateAction() {
    if (this->counter >= FRAMES_PER_LAUNCH) {
        this->counter = 0;
        this->fireABullet();
    } else {
        this->counter += 1;
    }
}

Bullet *Launcher::fireABullet() {
    // TODO: Se llama fuera del step, no es necesario lanzar un new instruction.
    float x = this->getPosX();
    float y = this->getPosY();

    Instruction *inst = 0;
    switch (this->direction) {
        case DIRECTION::RIGHT_DIRECTION:
            x += MIN_CREATE_DISTANCE;
            inst = new CreateBulletInstruction(
                this->world, b2Vec2(x, y), DIRECTION::RIGHT_DIRECTION);
            break;
        case DIRECTION::LEFT_DIRECTION:
            x -= MIN_CREATE_DISTANCE;
            inst = new CreateBulletInstruction(
                this->world, b2Vec2(x, y), DIRECTION::LEFT_DIRECTION);
            break;
        case DIRECTION::UP_DIRECTION:
            y += MIN_CREATE_DISTANCE;
            inst = new CreateBulletInstruction(
                this->world, b2Vec2(x, y), DIRECTION::UP_DIRECTION);
            break;
        case DIRECTION::DOWN_DIRECTION:
            y -= MIN_CREATE_DISTANCE;
            inst = new CreateBulletInstruction(
                this->world, b2Vec2(x, y), DIRECTION::DOWN_DIRECTION);
            break;
    }
    this->world->addInstruction(inst);
    return 0;
}
