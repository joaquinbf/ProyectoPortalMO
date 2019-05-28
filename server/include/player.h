#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "input_receiver.h"
#include "command.h"


class Player {
private:
    Protocol protocol;
    uint32_t player_id;
    InputReceiver input_receiver;

public:
    Player(Socket socket, ProtectedQueue<Command *> *commands);
    void start();
    void stop();
};

#endif
