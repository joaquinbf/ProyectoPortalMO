#ifndef __WORLD_H__
#define __WORLD_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/creatorMessage.h"
#include "../../common/include/entity.h"
#include "chell.h"
#include "player.h"
#include "chell.h"
#include "body.h"
#include "block.h"
#include "input_receiver.h"
#include <vector>
#include <map>

class Player;

class World: public Thread {
private:
    bool keep_running;
    b2World b2world;
    const float TIME_STEP = 1/20.0;
    const uint32_t VELOCITY_ITERATIONS = 8;
    const uint32_t POSITION_ITERATIONS = 3;
    std::vector<Player *> players;
    std::vector<Body *> bodies;
    std::map<Player *, Chell *> chells;

public:
    World();
    ~World();
    virtual void run() override;
    void stop();
    void addPlayer(Player *player);
    void createWorldOne();
    void sendBodiesToPlayer(Player *player);
    void addInputsFromAllPlayers();
    void addInputsFrom(Player *player);
    void updateAllPlayers();
    void updatePlayer(Player *player);
    void freeBodies();
};

#endif
