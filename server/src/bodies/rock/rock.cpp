#include "../../../include/bodies/rock/rock.h"

#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/chell/chell.h"
#include <cstdint>


Rock::Rock(World *world, float x, float y):
    Body(world, ENTITY::ROCK) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;

    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(WIDTH/2, HEIGHT/2);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;

    this->b2body->CreateFixture(&boxFixtureDef);
}

Rock::~Rock() {
    this->world->getB2World()->DestroyBody(this->b2body);
}

Update Rock::createUpdate(COMMAND command) const {
    Update update(
        command,
        ENTITY::ROCK,
        this->getBodyId(),
        STATUS::NONE_STATUS,
        this->getPosX() * ZOOM_FACTOR,
        this->getPosY() * ZOOM_FACTOR,
        0);
    return update;
}

void Rock::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);

}

void Rock::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Rock::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->handleBeginContactWith(this, contact);
}
