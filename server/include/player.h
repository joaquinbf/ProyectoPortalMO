#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <cstdint>
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include "../include/inputReceiver.h"
#include "../include/updateSender.h"

class Player {
private:
    Protocol protocol;
    uint32_t player_id;    
    InputReceiver inputReceiver;
    UpdateSender updateSender;
public:
    explicit Player(Socket socket);
    ~Player();
    void start();
    void stop();
    void sendChellIdToClient() const;
    void setInputPtr(ProtectedQueue<Action>* ptr);
};

#endif
