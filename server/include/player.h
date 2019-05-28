#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../common/include/socket.h"
#include "./chell/chell.h"

class Player {
    Socket socket;
    Chell *chell;

public:
    Player(Socket socket, Chell *chell);
};

#endif
