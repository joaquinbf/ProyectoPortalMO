#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "../include/inputReceiver.h"
#include "../include/updateSender.h"

class Player {
private:
    Protocol protocol;
    uint32_t player_id;
    ProtectedQueue<Action>* inputsPtr;    
    InputReceiver inputReceiver;
    UpdateSender updateSender;
public:
    Player(Socket socket);
    void start();
    void stop();
    void sendChellIdToClient() const;
    void setInputPtr(ProtectedQueue<Action>* ptr);
};

#endif
