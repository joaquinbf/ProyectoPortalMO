#include "../include/block.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

Block::Block(b2World *b2world, float x, float y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = this->ANGLE;

    this->b2body = b2world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(this->HALF_WIDTH, this->HALF_HEIGHT);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = this->DENSITY;

    this->b2body->CreateFixture(&boxFixtureDef);
}
