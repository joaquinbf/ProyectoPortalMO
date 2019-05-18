#ifndef __STAGE_H__
#define __STAGE_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../common/include/thread.h"
#include <cstdint>

class Stage: public Thread {
private:
    const b2Vec2 GRAVITY;
    b2World b2world;
    bool keep_running;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;

public:
    Stage();
    virtual void run() override;
    void stop();
};

#endif
