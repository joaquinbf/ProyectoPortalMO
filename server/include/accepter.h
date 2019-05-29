#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

#include "match.h"
#include "player.h"
#include "../../common/include/socket.h"
#include "../../common/include/port.h"
#include "../../common/include/thread.h"

class Accepter: public Thread {
private:
    Socket socket;
    bool keep_running;

public:
    Accepter();
    virtual void run() override;
    void stop();
};

#endif
