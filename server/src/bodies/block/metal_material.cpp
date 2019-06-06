#include "../../../include/bodies/block/metal_material.h"

#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../../common/include/types.h"
#include "../../../include/update_factories/update_factory.h"

void MetalMaterial::fillIdClassWithShape(
    Update &update,
    const UpdateFactory *update_factory,
    const DiagonalShape *shape) const {
    update_factory->fillIdClass(update, shape, this);
}

void MetalMaterial::fillIdClassWithShape(
    Update &update,
    const UpdateFactory *update_factory,
    const SquareShape *shape) const {
    update_factory->fillIdClass(update, shape, this);
}
