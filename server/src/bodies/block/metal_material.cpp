#include "../../../include/bodies/block/metal_material.h"

#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../../common/include/types.h"


ENTITY MetalMaterial::createEntityWithShape(DiagonalShape *diagonal_shape) {
    return ENTITY::METAL_TRIAG_BLOCK;
}

ENTITY MetalMaterial::createEntityWithShape(SquareShape *square_shape) {
    return ENTITY::METAL_BLOCK;
}
