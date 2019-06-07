#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/rock/rock.h"
#include <iostream>

Button::Button(uint32_t body_id, b2World *b2world, float x, float y):
    Body(body_id, ENTITY::BUTTON) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x -Cx, y - Cy);
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;
    this->b2body = b2world->CreateBody(&bodyDef);

    b2Vec2 vertices[4];
    vertices[0].Set(P1);
    vertices[1].Set(P2);
    vertices[2].Set(P3);
    vertices[3].Set(P4);

    b2PolygonShape b2polygonshape;
    b2polygonshape.Set(vertices, 4);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &b2polygonshape;
    this->b2body->CreateFixture(&fixtureDef);
    this->is_pressed = false;
}

bool Button::isPressed() const {
    return this->is_pressed;
}

Update Button::createUpdate(COMMAND command) const {
    std::cout << "UPDATE BUTTON" << std::endl;
    std::cout << "POS BUTTON SERVER : ("
              << this->b2body->GetPosition().x  << ", "
              << this->b2body->GetPosition().y  << " ) "
              << std::endl;
    Update update(
        command,
        this->entity,
        this->getBodyId(),
        this->is_pressed ? STATUS::BUTTON_ON: STATUS::BUTTON_OFF,
        (this->b2body->GetPosition().x + Cx) * ZOOM_FACTOR,
        (this->b2body->GetPosition().y + Cy) * ZOOM_FACTOR,
        0);
    return update;
}


void Button::press() {
    this->is_pressed = true;
}

void Button::release() {
    this->is_pressed = false;
}

void Button::notifyStatusChangeTo(Gate *gate) {
    this->gate = gate;
}

bool Button::getAsBoolean() const {
    return this->isPressed();
}

void Button::handleBeginContactWith(Body *other_body) {
    other_body->handleBeginContactWith(this);
}

void Button::handleBeginContactWith(Chell *chell) {
    this->press();
    chell->changeStateToIdle();
}

void Button::handleEndContactWith(Body *other_body) {
    other_body->handleEndContactWith(this);
}

void Button::handleEndContactWith(Chell *chell) {
    this->release();
}
