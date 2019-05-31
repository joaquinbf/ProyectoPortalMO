#ifndef __SQUARE_SHAPE_H__
#define __SQUARE_SHAPE_H__

#include "shape.h"

class SquareShape: public Shape {
public:
    virtual b2PolygonShape giveShape(
        float half_with, float half_height) override;
};

#endif
