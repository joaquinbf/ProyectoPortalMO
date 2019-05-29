#ifndef __MATCH_H__
#define __MATCH_H__

#include "world.h"
#include "./chell/chell.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include <cstdint>
#include <vector>

#define GRAVITY b2Vec2(0.0, -9.8)

class Match: public Thread {
private:
    bool keep_running;
    b2World b2world;
    World world;

public:
    Match();
    virtual void run() override;
    void stop();
    Chell *createChell();
};

#endif
