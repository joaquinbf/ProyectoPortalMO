#ifndef __WORLD_H__
#define __WORLD_H__

#include "body.h"
#include "chell/chell.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include <map>
#include <vector>
#include <mutex>

class World {
private:
    b2World *b2world;
    uint32_t body_count;
    std::map<uint32_t, Chell *> chells;
    std::vector<Body *> bodies;
    std::mutex m;

public:
    World(b2World *b2world);
    ~World();
    Chell *createChell();
};

#endif
