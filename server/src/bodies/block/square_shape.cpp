#include "../../../include/bodies/block/square_shape.h"
#include "../../../include/bodies/block/material.h"
#include "../../../include/update_factory.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"

b2PolygonShape SquareShape::giveShape(float half_with, float half_height) {
    b2PolygonShape boxShape;
    boxShape.SetAsBox(half_with, half_height);
    return boxShape;
}

void SquareShape::fillIdClassWithMaterial(
    Update &update,
    const UpdateFactory *update_factory,
    const Material *material) const {
    material->fillIdClassWithShape(update, update_factory, this);
}
