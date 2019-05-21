#ifndef __WORLD_H__
#define __WORLD_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../common/include/thread.h"
#include "../include/player.h"
#include "../include/input_receiver.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include <vector>

class World: public Thread {
private:
    bool keep_running;
    b2World b2world;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;
    std::vector<Player *> players;

public:
    /* Ejecuta a world */
    World();
    virtual void run() override;
    void stop();
    void addPlayer(Player *player);
};

#endif
