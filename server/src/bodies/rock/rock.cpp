#include "../../../include/bodies/rock/rock.h"

#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../include/bodies/button/button.h"
#include <cstdint>


Rock::Rock(World *world, float x, float y):
    Body(world, ENTITY::ROCK) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = this->ANGLE;
    bodyDef.userData = (void *) this;
    bodyDef.fixedRotation = true;

    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(this->HALF_WIDTH, this->HALF_HEIGHT);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = this->DENSITY;

    this->b2body->CreateFixture(&boxFixtureDef);
}

Rock::~Rock() {
}

Update Rock::createUpdate(COMMAND command) const {
    Update update(
        command,
        ENTITY::ROCK,
        this->getBodyId(),
        STATUS::NONE_STATUS,
        this->b2body->GetPosition().x,
        this->b2body->GetPosition().y,
        0);
    return update;
}

void Rock::handleBeginContactWith(Body *other_body) {
    other_body->handleBeginContactWith(this);

}

void Rock::handleEndContactWith(Body *other_body) {
    other_body->handleEndContactWith(this);
}
