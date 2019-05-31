#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

class Shape {
public:
    virtual b2PolygonShape giveShape(float half_with, float half_height) = 0;
    virtual ~Shape();
};

#endif