#ifndef __METAL_MATERIAL_H__
#define __METAL_MATERIAL_H__

#include "material.h"

class DiagonalShape;
class SquareShape;
class Portal;

class MetalMaterial: public Material {
public:
    virtual ENTITY createEntityWithShape(DiagonalShape *diagonal_shape) override;
    virtual ENTITY createEntityWithShape(SquareShape *square_shape) override;
    virtual void tryOpenPortal(Portal *portal, b2Vec2 point, b2Vec2 normal);
};

#endif
