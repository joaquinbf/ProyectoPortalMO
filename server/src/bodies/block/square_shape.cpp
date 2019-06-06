#include "../../../include/bodies/block/square_shape.h"
#include "../../../include/bodies/block/material.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"


b2PolygonShape SquareShape::giveShape(float half_with, float half_height) {
    b2PolygonShape boxShape;
    boxShape.SetAsBox(half_with, half_height);
    return boxShape;
}

ENTITY SquareShape::createEntityWithMaterial(Material *material) {
    return material->createEntityWithShape(this);
}
