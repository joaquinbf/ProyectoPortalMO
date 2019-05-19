#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2Body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"

class Block {
private:
    b2Body *b2body;
    const float HALF_WIDTH = 1;
    const float HALF_HEIGHT = 1;
    const float DENSITY = 1;
    const float ANGLE = 0;

public:
    /* Instancia un bloque de 2x2 metros con su centro en la
     * posicion (x, y) de world */
    Block(b2World *b2world, float x, float y);
};

#endif