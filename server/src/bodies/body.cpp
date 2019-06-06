#include "../../include/bodies/body.h"
#include "../../include/update_factories/update_factory.h"


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
