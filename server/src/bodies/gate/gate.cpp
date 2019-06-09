#include "../../../include/bodies/gate/gate.h"

#include "../../../include/world.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/rock/rock.h"
#include <iostream>

Gate::Gate( World *world, float x, float y):
    Body(world, ENTITY::GATE),
    width(this->MAX_WIDTH),
    height(this->MAX_HEIGHT),
    closed_gate_state(this),
    opening_gate_state(this),
    open_gate_state(this),
    closing_gate_state(this),
    state(&this->closed_gate_state) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x - (MAX_WIDTH/2), y + (MAX_HEIGHT/2));
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;
    this->b2body = world->getB2World()->CreateBody(&bodyDef);

    b2PolygonShape b2polygonshape;
    b2Vec2 vertices[4];
    vertices[0].Set(0.00, 0.00);
    vertices[1].Set(MAX_WIDTH, 0.00);
    vertices[2].Set(MAX_WIDTH, -MAX_HEIGHT);
    vertices[3].Set(0.00, -MAX_HEIGHT);
    b2polygonshape.Set(vertices, 4);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &b2polygonshape;
    this->b2body->CreateFixture(&fixtureDef);
}

Update Gate::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->BODY_ID,
        this->state->getStatus(),
        (this->b2body->GetPosition().x + (MAX_WIDTH/2))* ZOOM_FACTOR,
        (this->b2body->GetPosition().y - (MAX_HEIGHT/2))* ZOOM_FACTOR,
        0);
    return update;
}

void Gate::setBooleanSupplier(BooleanSupplier *boolean_supplier) {
    this->boolean_supplier = boolean_supplier;
}

void Gate::handleBeginContactWith(Body *other_body) {
    other_body->handleBeginContactWith(this);
}

void Gate::handleEndContactWith(Body *other_body) {
    other_body->handleEndContactWith(this);
}

void Gate::applyStateAction() {
    this->state->applyStateAction();
}


void Gate::tryChangeState() {
    this->state->tryChangeState();
}

bool Gate::conditionIsMeet() {
    return this->boolean_supplier->getAsBoolean();
}

void Gate::changeStateToOpening() {
    this->state = &this->opening_gate_state;
}

void Gate::changeStateToOpen() {
    this->state = &this->open_gate_state;
}

void Gate::changeStateToClosing() {
    this->state = &this->closing_gate_state;
}

void Gate::changeStateToClosed() {
    this->state = &this->closed_gate_state;
}



void Gate::shrink() {
    b2Fixture *b2fixture = this->b2body->GetFixtureList();
    b2PolygonShape *b2polygonshape = (b2PolygonShape *) b2fixture->GetShape();

    if (this->height - SIZE_RATE*8 > MIN_HEIGHT) {
        this->height -= SIZE_RATE*8;
    } else {
        this->height = MIN_HEIGHT;
    }

    b2Vec2 vertices[4];
    vertices[0].Set(0.00, 0.00);
    vertices[1].Set(MAX_WIDTH, 0.00);
    vertices[2].Set(MAX_WIDTH, -this->height);
    vertices[3].Set(0.00, -this->height);

    b2polygonshape->Set(vertices, 4);
}

void Gate::grow() {
    b2Fixture *b2fixture = this->b2body->GetFixtureList();
    b2PolygonShape *b2polygonshape = (b2PolygonShape *) b2fixture->GetShape();

    if (this->height + SIZE_RATE < MAX_HEIGHT) {
        this->height += SIZE_RATE;
    } else {
        this->height = MAX_HEIGHT;
    }

    b2Vec2 vertices[4];
    vertices[0].Set(0.00, 0.00);
    vertices[1].Set(MAX_WIDTH, 0.00);
    vertices[2].Set(MAX_WIDTH, -this->height);
    vertices[3].Set(0.00, -this->height);

    b2polygonshape->Set(vertices, 4);
}

bool Gate::isOnMinSize() const {
    return this->height == MIN_HEIGHT;
}

bool Gate::isOnMaxSize() const {
    return this->height == MAX_HEIGHT;
}
