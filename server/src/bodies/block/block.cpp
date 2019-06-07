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


Block::Block(
    uint32_t body_id, b2World *b2world,
    float x, float y,
    Shape *shape, Material *material):
    Body(body_id, shape->createEntityWithMaterial(material)),
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
    boxFixtureDef.userData = (void *) this;

    b2Fixture* b2fixture = this->b2body->CreateFixture(&boxFixtureDef);
    b2fixture->SetUserData((void *)this);

    this->shape = shape;
    this->material = material;
}

Block::~Block() {
    delete shape;
    delete material;
}

Update Block::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        0);
    return update;
}

void Block::handleBeginContactWith(Body *other_body) {
    other_body->handleBeginContactWith(this);
}

void Block::handleBeginContactWith(Chell *chell) {
    chell->changeStateToIdle();
}

void Block::handleEndContactWith(Body *other_body) {
    other_body->handleEndContactWith(this);
}
