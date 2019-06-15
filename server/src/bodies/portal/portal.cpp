#include "../../../include/bodies/portal/portal.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2EdgeShape.h"
#include "../../../include/world.h"
#include "../../../include/instructions/teleport_body_instruction.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/bodies/chell/chell.h"
#include <iostream>
#include <cmath>

Portal::Portal(World *world, uint8_t portal_number, b2Vec2 pos, b2Vec2 normal):
    Body(world, portal_number == NPORTAL1 ? ENTITY::PORTAL1 : ENTITY::PORTAL2),
    normal(normal),
    opposite(nullptr) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.position.Set(pos.x, pos.y);
    b2bodydef.angle = acos(normal.x/normal.Length()) - (PI/2);
    b2bodydef.fixedRotation = true;
    b2bodydef.userData = (void *) this;
    b2bodydef.active = true;
    b2bodydef.awake = false;

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2PolygonShape b2polygonshape;
    b2polygonshape.SetAsBox(WIDTH/2, HEIGHT/2);

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2polygonshape;
    b2fixturedef.isSensor = true;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
    this->world->addUpdate(this->createUpdate(COMMAND::CREATE_COMMAND));
}

Portal::~Portal() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

void Portal::teleportBody(Body *body) const {
    b2Vec2 v = body->getLinearVelocity();
    b2Vec2 new_v = v.Length() * this->normal;
    b2Vec2 new_pos = this->getPosition() + 0.3*this->normal;
    float new_angle = acos(
        (v.x*normal.x + v.y*normal.y)/(v.Length()*normal.Length()));
    Instruction *inst = new TeleportBodyInstruction(
        body, new_v, new_pos, new_angle);
    this->getWorld()->addInstruction(inst);
}


void Portal::teleportToOppositePortal(Body *body) const {
    if (this->opposite != nullptr) {
        this->opposite->teleportBody(body);
    }
}


void Portal::setOppositePortal(Portal *opposite) {
    this->opposite = opposite;
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
    this->teleportToOppositePortal(bullet);
}

void Portal::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    this->teleportToOppositePortal(chell);
}
