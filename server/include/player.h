#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../include/player.h"
#include "../include/input_receiver.h"

class Player: public Thread {
private:
    bool keep_running;
    Protocol protocol;

public:
    Player(Socket &socket);
    virtual void run() override;
};

#endif
