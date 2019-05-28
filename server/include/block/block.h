#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../body.h"

#include "shape.h"
#include "material.h"

#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"

class Block: public Body {
private:
    b2Body *b2body;
    const float HALF_WIDTH = 100;
    const float HALF_HEIGHT = 100;
    const float DENSITY = 1;
    const float ANGLE = 0;
    Shape *shape;
    Material *material;

public:
    /* Instancia un bloque con su centro en la posicion (x, y)
     * de world con propiedades de shape y material.*/
    Block(b2World *b2world, float x, float y, Shape *shape, Material *material);
    ~Block();
    virtual Update getCreateUpdate() override;
    virtual Update getUpdate() override;
};

#endif
