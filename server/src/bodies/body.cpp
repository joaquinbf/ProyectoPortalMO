#include "../../include/bodies/body.h"

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
