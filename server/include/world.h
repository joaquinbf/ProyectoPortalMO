#ifndef __WORLD_H__
#define __WORLD_H__

#include "../../libs/Box2D-master/Box2D/Dynamics/b2World.h"
#include "../../libs/Box2D-master/Box2D/Common/b2Math.h"
#include "../../common/include/thread.h"
#include "../include/player.h"
#include "../include/chell.h"
#include "../include/body.h"
#include "../include/input_receiver.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include "../../common/include/creatorMessage.h"
#include "../../common/include/entity.h"
#include <vector>

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

public:
    /* Ejecuta a world */
    World();
    virtual void run() override;
    void stop();
    void addPlayer(Player *player);
    void createWorldOne();
    void sendBodiesToPlayer(Player *player);
    void addInputsFromAllPlayers();
    void addInputsFrom(Player *player);
    void updateAllPlayers();
    void updatePlayer(Player *player);
};

#endif
