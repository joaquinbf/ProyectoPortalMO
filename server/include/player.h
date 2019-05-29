#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "match.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"

class Player: public Thread {
private:
    bool keep_running;
    Socket socket;
    Match *match;

public:
    Player(Socket &&socket, Match *match);
    virtual void run() override;
    void stop();
};

#endif
