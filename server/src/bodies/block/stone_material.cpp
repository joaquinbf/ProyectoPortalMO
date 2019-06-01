#include "../../../include/bodies/block/stone_material.h"

#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../../common/include/types.h"


ENTITY StoneMaterial::createEntityWithShape(DiagonalShape *diagonal_shape) {
    return ENTITY::NONE_ENTITY;
}

ENTITY StoneMaterial::createEntityWithShape(SquareShape *square_shape) {
    return ENTITY::STONE_BLOCK;
}
