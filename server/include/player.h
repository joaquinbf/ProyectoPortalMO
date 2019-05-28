#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "input_receiver.h"

class Command;
class Chell;

class Player {
private:
    Protocol protocol;
    uint32_t player_id;
    InputReceiver input_receiver;
    Chell *chell;

public:
    Player(Socket socket, ProtectedQueue<Command *> *commands);
    void start();
    void stop();
    void setChell(Chell *chell);
    void sendChellIdToClient();
};

#endif
