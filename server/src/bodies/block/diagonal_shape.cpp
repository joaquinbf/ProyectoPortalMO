#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/material.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"

b2PolygonShape DiagonalShape::giveShape(float half_with, float half_height) {
    // TODO: Hacer que sea un triagulo.
    b2PolygonShape boxShape;
    boxShape.SetAsBox(half_with, half_height);
    return boxShape;
}

ENTITY DiagonalShape::createEntityWithMaterial(Material *material) {
    return material->createEntityWithShape(this);
}
