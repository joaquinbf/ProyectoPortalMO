#include "../../../include/bodies/portal/portal.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2EdgeShape.h"
#include "../../../include/world.h"
#include "../../../include/instructions/transform_body_instruction.h"
#include <iostream>

Portal::Portal(World *world, uint8_t portal_number, b2Vec2 pos, b2Vec2 normal):
    Body(world, portal_number == 1 ? ENTITY::PORTAL1 : ENTITY::PORTAL2),
    normal(normal) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.position.Set(pos.x, pos.y);
    b2bodydef.angle = acos(normal.x/normal.Length()) - (PI/2);
    b2bodydef.fixedRotation = true;
    b2bodydef.userData = (void *) this;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(WIDTH/2, HEIGHT/2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.isSensor = true;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
}

Portal::~Portal() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

Update Portal::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->getPosX() * ZOOM_FACTOR,
        this->getPosY() * ZOOM_FACTOR,
        0);
    return update;
}

void Portal::handleBeginContactWith(Body *body, b2Contact *contact) {
    body->handleBeginContactWith(this, contact);
}

void Portal::handleEndContactWith(Body *body, b2Contact *contact) {
    body->handleEndContactWith(this, contact);
}

void Portal::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
}
