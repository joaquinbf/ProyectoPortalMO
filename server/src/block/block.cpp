#include "../../include/block/block.h"

Block::Block(
    b2World *b2world, float x, float y,
    Shape *shape, Material *material) {
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

    this->shape = shape;
    this->material = material;
}

Block::~Block() {
    if (this->shape != 0) {
        delete this->shape;
    }

    if (this->material != 0) {
        delete this->material;
    }
}
