#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../include/player.h"
#include "../include/input_receiver.h"
#include "../include/body.h"
#include "../../common/include/entity.h"
#include "../../common/include/creatorMessage.h"
#include <vector>

class Player: public Thread {
private:
    bool keep_running;
    Protocol protocol;
    InputReceiver input_recv;

public:
    Player(Socket &socket);
    virtual void run() override;
    void stop();
    InputReceiver *getInputReceiver();
    Protocol *getProtocol();
    void sendBodies(const std::vector<Body *> &bodies);
};

#endif
