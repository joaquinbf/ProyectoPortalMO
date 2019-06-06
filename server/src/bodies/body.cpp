#include "../../include/bodies/body.h"
#include "../../include/update_factory.h"


Body::Body(uint32_t body_id):
    BODY_ID(body_id) {
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

void Body::fillPosition(Update &update, const UpdateFactory *update_factory) const {
    update_factory->fillPosition(
        update,
        this->b2body->GetPosition().x,
        this->b2body->GetPosition().y);
}

void Body::fillDirection(
    Update &update,
    const UpdateFactory *update_factory) const {
    update_factory->fillDirection(update, this);
}
