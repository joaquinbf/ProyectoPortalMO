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
    bodyDef.position.Set(x, y);
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;
    this->b2body = b2world->CreateBody(&bodyDef);

    b2Vec2 vertices[4];
    vertices[0].Set(1.20, 0.30);
    vertices[1].Set(1.70, 0.0);
    vertices[2].Set(0.0, 0.0);
    vertices[3].Set(0.60, 0.30);

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
    Update update(
        command,
        this->entity,
        this->getBodyId(),
        this->is_pressed ? STATUS::BUTTON_ON: STATUS::BUTTON_OFF,
        this->b2body->GetPosition().x * ZOOM_FACTOR,
        this->b2body->GetPosition().y * ZOOM_FACTOR,
        0);
    return update;
}

void Button::fillDetails(Update &update, const UpdateFactory *update_factory) const {
    
}


void Button::press() {
    this->is_pressed = true;
}

void Button::release() {
    this->is_pressed = false;
}


void Button::handleBeginContactWith(Body *other_body) {
    other_body->letBeginContactBeHandledBy(this);
}

void Button::letBeginContactBeHandledBy(Chell *chell) {
    this->press();
    this->gate->notifyStateChange();
}

void Button::letBeginContactBeHandledBy(Block *block) {
}

void Button::letBeginContactBeHandledBy(Button *button) {
}

void Button::letBeginContactBeHandledBy(Gate *gate) {
}

void Button::letBeginContactBeHandledBy(Rock *rock) {
    this->press();
    this->gate->notifyStateChange();
}

void Button::notifyStatusChangeTo(Gate *gate) {
    this->gate = gate;
}

bool Button::getAsBoolean() const {
    return this->isPressed();
}
