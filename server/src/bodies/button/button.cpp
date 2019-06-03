#include "../../../include/bodies/button/button.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/block/block.h"
#include "../../../include/bodies/gate/gate.h"
#include <iostream>

Button::Button(uint32_t body_id, b2World *b2world, float x, float y):
    Body(body_id) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(x, y);
    bodyDef.userData = (void *) this;
    bodyDef.awake = false;
    this->b2body = b2world->CreateBody(&bodyDef);

    b2Vec2 vertices[4];
    vertices[0].Set(120, 30);
    vertices[1].Set(170, 0);
    vertices[2].Set(0, 0);
    vertices[3].Set(60, 30);

    b2PolygonShape b2polygonshape;
    b2polygonshape.Set(vertices, 4);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &b2polygonshape;
    this->b2body->CreateFixture(&fixtureDef);
}

bool Button::isPressed() {
    return this->is_pressed;
}

Update Button::createUpdate(COMMAND command) const {
    Update update(
        command,
        this->entity,
        this->getBodyId(),
        this->is_pressed ? STATUS::BUTTON_ON: STATUS::BUTTON_OFF,
        this->b2body->GetPosition().x,
        this->b2body->GetPosition().y,
        0);
    return update;
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
    std::cout << "Is the button pressed ? " << this->isPressed() << std::endl;
}

void Button::letBeginContactBeHandledBy(Block *block) {
}

void Button::letBeginContactBeHandledBy(Button *button) {
}

void Button::letBeginContactBeHandledBy(Gate *gate) {
}
