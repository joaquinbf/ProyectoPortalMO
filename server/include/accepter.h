#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

#include "../../common/include/thread.h"
#include "../../common/include/socket.h"

class Accepter: public Thread {
private:
    Socket *socket;
    bool keep_running;
public:
    Accepter(Socket *socket);
    virtual void run() override;
};

#endif
