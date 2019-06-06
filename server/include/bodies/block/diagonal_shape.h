#ifndef __DIAGONAL_SHAPE_H__
#define __DIAGONAL_SHAPE_H__

#include "shape.h"

class DiagonalShape: public Shape {
public:
    virtual b2PolygonShape giveShape(
        float half_with, float half_height) override;
};

#endif
