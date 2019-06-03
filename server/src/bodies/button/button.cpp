#include "../../../include/bodies/button/button.h"

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
    vertices[3].Set(50, 30);

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


void Button::handleBeginContactWith(Body *other_body) {
}

void Button::letBeginContactBeHandledBy(Chell *chell) {
}
