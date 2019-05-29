#ifndef __INPUT_RECEIVER_H__
#define __INPUT_RECEIVER_H__

#include "command/command.h"
#include "command/command_factory.h"
#include "../../common/include/thread.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"


class InputReceiver: public Thread {
private:
    bool keep_running;
    Protocol *protocol;
    ProtectedQueue<Command *> *command_queue;

public:
    InputReceiver(Protocol *protocol, ProtectedQueue<Command *> *command_queue);
    virtual void run() override;
    void stop();
};

#endif
