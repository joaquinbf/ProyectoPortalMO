#ifndef __WORLD_CORE_H__
#define __WORLD_CORE_H__

#include "bodies/body.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include <cstdint>
#include <vector>

class WorldCore {
private:
    b2World *b2world;
    uint32_t body_count;
    std::vector<Body *> bodies;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;

public:
    /* Instancia un world core sobre b2world. */
    WorldCore(b2World *b2world);

    /* Libera los recursos utilizados. */
    ~WorldCore();
    
private:
    /* Libera los bodies creados */
    void deleteBodies();
};

#endif
