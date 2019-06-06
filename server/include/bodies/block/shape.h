#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include "../../../../common/include/types.h"
#include "../../../../common/include/update.h"


class UpdateFactory;
class Material;

class Shape {
public:
    virtual b2PolygonShape giveShape(float half_with, float half_height) = 0;

    virtual void fillIdClassWithMaterial(
        Update &update,
        const UpdateFactory *update_factory,
        const Material *material) const = 0;
    virtual ~Shape();
};

#endif
