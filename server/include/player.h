#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "./chell/chell.h"

class Player {
    Protocol protocol;
    Chell *chell;

public:
    Player(Socket socket, Chell *chell);
    void start();
    void stop();
};

#endif
