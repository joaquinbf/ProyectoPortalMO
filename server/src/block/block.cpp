#include "../../include/block/block.h"

Block::Block(
    b2World *b2world, float x, float y,
    Shape *shape, Material *material) {
    this->body_number++;
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = this->ANGLE;
    bodyDef.userData = (void *) this;

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

Update Block::getCreateUpdate() {
    Update update(
        COMMAND::CREATE_COMMAND,
        ENTITY::STONE_BLOCK,
        this->body_number,
        STATUS::NONE_STATUS,
        (int32_t)this->b2body->GetPosition().x,
        (int32_t)this->b2body->GetPosition().y,
        0
    );

    return update;
}

Update Block::getUpdate() {
    Update update;
    return update;
}
