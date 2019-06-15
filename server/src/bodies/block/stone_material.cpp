#include "../../../include/bodies/block/stone_material.h"

#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../../common/include/types.h"
#include "../../../include/bodies/bullet/bullet.h"
#include "../../../include/instructions/destroy_body_instruction.h"

ENTITY StoneMaterial::createEntityWithShape(DiagonalShape *diagonal_shape) {
    return ENTITY::NONE_ENTITY;
}

ENTITY StoneMaterial::createEntityWithShape(SquareShape *square_shape) {
    return ENTITY::STONE_BLOCK;
}

bool StoneMaterial::canOpenPortalOnSurface() const {
    return false;
}

void StoneMaterial::handleBeginContactWith(Bullet *bullet) const {

}
