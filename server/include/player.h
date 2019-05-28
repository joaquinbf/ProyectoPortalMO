#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "./chell/chell.h"
#include "input_receiver.h"

class Player {
    Protocol protocol;
    Chell *chell;
    InputReceiver input_receiver;

public:
    Player(
        Socket socket,
        Chell *chell,
        ProtectedQueue<Command> *commands);

    void start();
    void stop();
};

#endif
