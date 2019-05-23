#ifndef __UPDATE_SENDER_H__
#define __UPDATE_SENDER_H__

#include "../../common/include/thread.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include <iostream>

class UpdateSender: public Thread {
private:
    bool keep_running;
    Protocol *protocol;
    ProtectedQueue<Update> queue;

public:
    UpdateSender(Protocol *protocol);
    virtual void run() override;
    void stop();
    ProtectedQueue<Update> *getQueue();
};

#endif
