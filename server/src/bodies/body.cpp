#include "../../include/bodies/body.h"

Body::Body(uint32_t body_id, ENTITY entity):
    BODY_ID(body_id),
    entity(entity) {
}

Body::~Body() {
}

uint32_t Body::getBodyId() const {
    return this->BODY_ID;
}

void Body::applyStateAction() {

}

bool Body::isAwake() const {
    return this->b2body->IsAwake();
}

void Body::fillBodyId(Update &update) const {
    update.setIdObject(this->BODY_ID);
}

void Body::fillPosition(Update &update, float zoom_factor) const {
    update.setPosX(this->b2body->GetPosition().x * zoom_factor);
    update.setPosY(this->b2body->GetPosition().y * zoom_factor);
}
