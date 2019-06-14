#ifndef __STONE_MATERIAL_H__
#define __STONE_MATERIAL_H__

#include "material.h"

class DiagonalShape;
class SquareShape;

class StoneMaterial: public Material {
public:
    virtual ENTITY createEntityWithShape(DiagonalShape *diagonal_shape) override;
    virtual ENTITY createEntityWithShape(SquareShape *square_shape) override;
};

#endif
