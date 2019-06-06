#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/block/shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/material.h"
#include "../../../include/bodies/block/metal_material.h"
#include "../../../include/bodies/block/stone_material.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/rock/rock.h"
#include "../../../include/update_factory.h"


Block::Block(
    uint32_t body_id, b2World *b2world,
    float x, float y,
    Shape *shape, Material *material):
    Body(body_id),
    shape(shape), material(material) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = this->ANGLE;
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;

    this->b2body = b2world->CreateBody(&bodyDef);

    b2PolygonShape b2polygonshape = this->shape->giveShape(this->HALF_WIDTH,
                                                           this->HALF_HEIGHT);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &b2polygonshape;
    boxFixtureDef.density = this->DENSITY;

    this->b2body->CreateFixture(&boxFixtureDef);

    this->shape = shape;
    this->material = material;
}

Block::~Block() {
    delete shape;
    delete material;
}

void Block::fillIdClass(
    Update &update,
    const UpdateFactory *update_factory) const {
    this->shape->fillIdClassWithMaterial(
        update,
        update_factory,
        this->material);
}

void Block::handleBeginContactWith(Body *other_body) {
    other_body->letBeginContactBeHandledBy(this);
}

void Block::letBeginContactBeHandledBy(Chell *chell) {
    chell->changeStateToIdle();
}

void Block::letBeginContactBeHandledBy(Block *block) {
}

void Block::letBeginContactBeHandledBy(Button *button) {
}

void Block::letBeginContactBeHandledBy(Gate *gate) {
}

void Block::letBeginContactBeHandledBy(Rock *rock) {
}
