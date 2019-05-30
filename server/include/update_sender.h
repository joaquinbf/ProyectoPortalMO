#ifndef __UPDATE_SENDER_H__
#define __UPDATE_SENDER_H__

#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../common/include/protocol.h"
#include "../../common/include/exceptions.h"


class UpdateSender: public Thread {
private:
    Protocol *protocol;
    bool keep_running;
    ProtectedQueue<Update> update_queue;

public:
    UpdateSender(Protocol *protocol);
    virtual void run() override;
    void stop();
    ProtectedQueue<Update> *getUpdateQueue();
};

#endif
