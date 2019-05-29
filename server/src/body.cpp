#include "../include/body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"

Body::Body(uint32_t body_id):
    body_id(body_id),
    b2body(0) {
}

Body::~Body() {
}

uint32_t Body::getBodyId() {
    return this->body_id;
}
