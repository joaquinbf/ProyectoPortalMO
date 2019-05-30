#ifndef __UPDATE_SENDER_H__
#define __UPDATE_SENDER_H__

#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"


class UpdateSender: public Thread {
private:
    bool keep_running;
    ProtectedQueue<Update> update_queue;

public:
    UpdateSender();
    virtual void run() override;
    void stop();
    ProtectedQueue<Update> *getUpdateQueue();
};

#endif
