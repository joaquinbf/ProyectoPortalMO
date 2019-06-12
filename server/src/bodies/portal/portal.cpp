#include "../../../include/bodies/portal/portal.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2EdgeShape.h"
#include "../../../include/world.h"
#include "../../../include/instructions/transform_body_instruction.h"
#include <iostream>

Portal::Portal(World *world, uint8_t number):
    Body(world, number == 1 ? ENTITY::PORTAL1 : ENTITY::PORTAL2),
    is_on(false) {
    b2BodyDef b2bodydef;
    b2bodydef.type = b2_staticBody;
    b2bodydef.active = false;
    b2bodydef.awake = false;
    b2bodydef.userData = (void *) this;
    b2bodydef.position.Set(-1, -1);

    this->b2body = world->getB2World()->CreateBody(&b2bodydef);

    b2EdgeShape b2edgeshape;
    b2edgeshape.Set(b2Vec2(0, 0), b2Vec2(2.20, 0));

    b2FixtureDef b2fixturedef;
    b2fixturedef.shape = &b2edgeshape;
    b2fixturedef.userData = (void *) this;

    this->b2body->CreateFixture(&b2fixturedef);
}

void Portal::transportToOppositePortal(Body *body) const {
    this->opposite->transportBody(body);
}

void Portal::transportBody(Body *body) const {
    std::cout << "void Portal::transportBody(Body *body) const" << std::endl;
    if (this->isActive()) {
        b2Vec2 new_pos(0, 0);
        new_pos += this->getPosition();
        new_pos += 1*normal;
        b2Vec2 w = normal;
        w.Normalize();
        body->setLinearVelocity(body->getLinearVelocity().Length()*normal);
        this->world->addInstruction(
            new TransformBodyInstruction(body, new_pos, this->getAngle() + 3.1415/2));
        std::cout << "Creada transformBody para bullet" << std::endl;

    }
}

void Portal::setPairWith(Portal *portal) {
    this->opposite = portal;
}

void Portal::setNormal(b2Vec2 normal) {
    this->normal = normal;
}

bool Portal::isOn() const {
    return is_on;
}

void Portal::turnOn() {
    this->is_on = true;
}

void Portal::turnOff() {
    this->is_on = false;
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
    std::cout << "choco con bullet" << std::endl;
    this->transportToOppositePortal(bullet);
}
