#include "../../../include/bodies/block/diagonal_shape.h"
#include "../../../include/bodies/block/material.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../../../common/include/types.h"

b2PolygonShape DiagonalShape::giveShape(float width, float height) {
    b2PolygonShape b2polygonshape;
    b2Vec2 vertices[3];
    vertices[0].Set(0.00, 0.00);
    vertices[1].Set(0.00, 2.00);
    vertices[2].Set(2.00, 0.00);
    b2polygonshape.Set(vertices, 3);
    return b2polygonshape;
}

ENTITY DiagonalShape::createEntityWithMaterial(Material *material) {
    return material->createEntityWithShape(this);
}
