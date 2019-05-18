#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "../../common/include/position.h"
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
    Block(b2World *b2world, float x, float y);
};

#endif
