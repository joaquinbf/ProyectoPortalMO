#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/port.h"

#include "../include/world.h"



class Accepter: public Thread {
private:
    Socket socket;
    bool keep_running;
    World world;

public:
    Accepter();
    virtual void run() override;
    void stop();
};

#endif
