#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "../../../../common/include/update.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/types.h"

class DiagonalShape;
class SquareShape;
class UpdateFactory;

class Material {
public:
    virtual ~Material();

    virtual void fillIdClassWithShape(
        Update &update,
        const UpdateFactory *update_factory,
        const DiagonalShape *shape) const = 0;

    virtual void fillIdClassWithShape(
        Update &update,
        const UpdateFactory *update_factory,
        const SquareShape *shape) const = 0;
};

#endif
