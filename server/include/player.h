#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "match.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"

class Player: public Thread {
private:
    bool keep_running;
    Protocol protocol;
    Match *match;

public:
    Player(Socket socket, Match *match);
    ~Player();
    virtual void run() override;
    void stop();
};

#endif
