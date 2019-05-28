#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/port.h"

#include "../include/match.h"

class Accepter: public Thread {
private:
    Socket socket;
    bool keep_running;
    Match match;

public:
    Accepter();
    virtual void run() override;
    void stop();
};

#endif
