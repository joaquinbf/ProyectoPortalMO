#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../body.h"
#include "shape.h"
#include "material.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../../../libs/Box2D-master/Box2D/Dynamics/b2Fixture.h"
#include "../../../../libs/Box2D-master/Box2D/Collision/Shapes/b2PolygonShape.h"
#include <cstdint>

class Block: public Body {
private:
    Shape *shape;
    Material *material;
    const float HALF_WIDTH = 52;
    const float HALF_HEIGHT = 108;
    const float DENSITY = 0.001;
    const float ANGLE = 0;

public:
    /* Instancia un block de id 'body_id' sobre b2world en la posicion (x, y)
     * de shape y material asignado.
     * Al liberarse el block tambien se libera shape y material. */
    Block(uint32_t body_id, b2World *b2world,
          float x, float y,
          Shape *shape, Material *material);

    /* Libera los recursos utilizados */
    ~Block();
};

#endif
