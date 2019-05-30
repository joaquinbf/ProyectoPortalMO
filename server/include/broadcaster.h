#ifndef __BROADCASTER_H__
#define __BROADCASTER_H__

#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../common/include/types.h"
#include "../../common/include/thread.h"

class Broadcaster: public Thread {
private:
    bool keep_running;
    ProtectedQueue<Update> *update_queue;

public:
    virtual void run() override;
    void stop();

private:
    void handleUpdate(const Update &update);
};

#endif
