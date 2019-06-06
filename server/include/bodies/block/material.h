#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"

class DiagonalShape;
class SquareShape;

class Material {
public:
    virtual ~Material();
    virtual ENTITY createEntityWithShape(DiagonalShape *diagonal_shape) = 0;
    virtual ENTITY createEntityWithShape(SquareShape *square_shape) = 0;
};

#endif
