#ifndef __INPUT_RECEIVER_H__
#define __INPUT_RECEIVER_H__

#include "../../common/include/thread.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/protocol.h"
#include "command.h"


class InputReceiver: public Thread {
public:
    Protocol *protocol;
    ProtectedQueue<Command *> *commands;
    bool keep_running;

public:
    InputReceiver(Protocol *protocol, ProtectedQueue<Command *> *commands);
    virtual void run() override;
    void stop();
};

#endif
