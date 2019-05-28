#ifndef __INPUT_RECEIVER_H__
#define __INPUT_RECEIVER_H__

#include "../../common/include/protected_queue.h"
#include "../../common/include/thread.h"
#include "../../common/include/action.h"
#include "../../common/include/protocol.h"

#include "command.h"
#include "left_command.h"
#include "default_command.h"
#include "chell/chell.h"

class InputReceiver: public Thread {
private:
    Chell *chell;
    Protocol *protocol;
    ProtectedQueue<Command *> *commands;
    bool keep_running;

public:
    InputReceiver(Chell *chell, Protocol *protocol, ProtectedQueue<Command *> *commands);
    virtual void run() override;
    void stop();
};

#endif
