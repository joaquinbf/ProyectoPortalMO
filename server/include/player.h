#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../player.h"

class Player: public Thread {
private:
    Socket socket;
    bool keep_running;
public:
    Player(Socket &socket);
    virtual void run() override;
};

#endif
