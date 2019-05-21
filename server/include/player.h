#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../include/player.h"

class Player: public Thread {
private:
    bool keep_running;
    Socket socket;

public:
    Player(Socket &socket);
    virtual void run() override;
};

#endif
