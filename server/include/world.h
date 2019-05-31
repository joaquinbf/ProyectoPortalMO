#ifndef __WORLD_H__
#define __WORLD_H__

#include "world_core.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

#define GRAVITY b2Vec2(0.0, -9.8)

class World {
private:
    b2World b2world;
    WorldCore world_core;

public:
    World();
};

#endif
