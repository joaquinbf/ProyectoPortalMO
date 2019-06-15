#include "../../../include/bodies/block/metal_material.h"

#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../include/bodies/portal/portal.h"
#include "../../../include/world.h"
#include "../../../include/instructions/transform_body_instruction.h"
#include "../../../../common/include/types.h"
#include <cmath>
#include <iostream>
#include "../../../include/bodies/bullet/bullet.h"

ENTITY MetalMaterial::createEntityWithShape(DiagonalShape *diagonal_shape) {
    return ENTITY::METAL_TRIAG_BLOCK;
}

ENTITY MetalMaterial::createEntityWithShape(SquareShape *square_shape) {
    return ENTITY::METAL_BLOCK;
}

bool MetalMaterial::canOpenPortalOnSurface() const {
    return true;
}

void MetalMaterial::handleBeginContactWith(Bullet *bullet) const {

}
