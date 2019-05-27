#ifndef __WORLD_H__
#define __WORLD_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"

class World {
private:
    b2World *b2world;

public:
    World(b2World *b2world);
};

#endif
