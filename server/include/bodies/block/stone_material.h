#ifndef __STONE_MATERIAL_H__
#define __STONE_MATERIAL_H__

#include "material.h"

class DiagonalShape;
class SquareShape;
class UpdateFactory;

class StoneMaterial: public Material {
public:
    virtual void fillIdClassWithShape(
        Update &update,
        const UpdateFactory *update_factory,
        const DiagonalShape *shape) const;

    virtual void fillIdClassWithShape(
        Update &update,
        const UpdateFactory *update_factory,
        const SquareShape *shape) const;
};

#endif
