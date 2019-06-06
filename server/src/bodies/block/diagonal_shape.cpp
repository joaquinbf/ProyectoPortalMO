#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/material.h"
#include "../../../include/bodies/block/square_shape.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"
#include "../../../include/update_factory.h"

b2PolygonShape DiagonalShape::giveShape(float half_with, float half_height) {
    // TODO: Hacer que sea un triagulo.
    b2PolygonShape boxShape;
    boxShape.SetAsBox(half_with, half_height);
    return boxShape;
}

void DiagonalShape::fillIdClassWithMaterial(
    Update &update,
    const UpdateFactory *update_factory,
    const Material *material) const {
    material->fillIdClassWithShape(update, update_factory, this);
}
