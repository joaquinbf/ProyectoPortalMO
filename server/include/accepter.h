#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

#include <vector>
#include <string>

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/port.h"

#include "../include/game.h"
#include "../include/player.h"
#include "../include/playerLogin.h"

class Accepter: public Thread {
private:
    Socket socket;
    bool keep_running;
    std::vector<Game*> games;
public:
    Accepter();
    ~Accepter();
    virtual void run() override;
    void stop();
};

#endif
