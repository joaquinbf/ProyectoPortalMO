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
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/world.h"

Block::Block(
    World *world,
    float x, float y, ORIENTATION orientation,
    SHAPE shape, MATERIAL material):
    Body(world, this->getEntity(shape, material)),
    orientation(orientation),
    shape(this->createShape(shape)),
    material(this->createMaterial(material)),
    def(world->getWorldConfig().block_def) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = -orientation * (3.1415/2);
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;


    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2PolygonShape b2polygonshape = this->shape->giveShape(WIDTH, HEIGHT);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &b2polygonshape;
    boxFixtureDef.density = this->DENSITY;
    boxFixtureDef.userData = (void *) this;
    boxFixtureDef.friction = this->def.friction;
    boxFixtureDef.restitution = 0.00;

    b2Fixture* b2fixture = this->b2body->CreateFixture(&boxFixtureDef);
    b2fixture->SetUserData((void *)this);

    this->shape = this->createShape(shape);
    this->material = this->createMaterial(material);
}

Block::~Block() {
    delete shape;
    delete material;
    this->world->getB2World()->DestroyBody(this->b2body);
}

bool Block::canOpenPortalOnSurface() const {
    return this->material->canOpenPortalOnSurface();
}


Update Block::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        STATUS::NONE_STATUS,
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        this->orientation);
    return update;
}

void Block::handleBeginContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleBeginContactWith(this, contact);
}

void Block::handleEndContactWith(Body *other_body, b2Contact *contact) {
    other_body->handleEndContactWith(this, contact);
}

void Block::handleBeginContactWith(Bullet *bullet, b2Contact *contact) {
    this->material->handleBeginContactWith(bullet, contact);
}

void Block::handleBeginContactWith(Chell *chell, b2Contact *contact) {
    chell->land();
}

ENTITY Block::getEntity(SHAPE shape, MATERIAL material) const {
    if (shape == SHAPE::SQUARE && material == MATERIAL::METAL) {
        return ENTITY::METAL_BLOCK;
    } else if (shape == SHAPE::SQUARE && material == MATERIAL::STONE) {
        return ENTITY::STONE_BLOCK;
    } else {
        return ENTITY::METAL_TRIAG_BLOCK;
    }
}

Shape *Block::createShape(SHAPE a_shape) {
    Shape *s= nullptr;
    switch (a_shape) {
        case SHAPE::DIAGONAL:
            s = new DiagonalShape();
            break;
        case SHAPE::SQUARE:
            s = new SquareShape();
            break;
    }
    return s;
}

Material *Block::createMaterial(MATERIAL a_material) {
    Material *m = nullptr;
    switch (a_material) {
        case MATERIAL::STONE:
            m = new StoneMaterial();
            break;
        case MATERIAL::METAL:
            m = new MetalMaterial();
            break;
    }
    return m;
}
