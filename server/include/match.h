#ifndef __MATCH_H__
#define __MATCH_H__

#include "world.h"

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"


#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"

class Match: public Thread {
private:
    const b2Vec2 GRAVITY;
    b2World b2world;
    bool keep_running;
    World world;

public:
    Match();
    virtual void run() override;
    void stop();
    void addPlayer(Socket socket);
};

#endif
