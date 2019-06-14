#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

class DiagonalShape;
class SquareShape;
class Portal;

class Material {
public:
    virtual ~Material();
    virtual ENTITY createEntityWithShape(DiagonalShape *diagonal_shape) = 0;
    virtual ENTITY createEntityWithShape(SquareShape *square_shape) = 0;
};

#endif
