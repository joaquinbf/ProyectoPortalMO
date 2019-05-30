#ifndef __BROADCASTER_H__
#define __BROADCASTER_H__

#include "../../common/include/protected_queue.h"
#include "../../common/include/update.h"
#include "../../common/include/types.h"
#include "../../common/include/thread.h"
#include <vector>

class Broadcaster: public Thread {
private:
    bool keep_running;
    ProtectedQueue<Update> *update_queue;
    std::vector<ProtectedQueue<Update> *> player_update_queues;

public:
    Broadcaster(ProtectedQueue<Update> *update_queue);
    virtual void run() override;
    void stop();
    void addPlayerUpdateQueue(
        ProtectedQueue<Update> *player_update_queue);

private:
    void handleUpdate(const Update &update);
    void updatePlayerQueues(const Update &update);
};

#endif
