#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../include/player.h"
#include "../include/world.h"

class Player: public Thread {
private:
    bool keep_running;
    Socket socket;
    World *world;

public:
    Player(Socket &socket, World *world);
    virtual void run() override;
};

#endif
