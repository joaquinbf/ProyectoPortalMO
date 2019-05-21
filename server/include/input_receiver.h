#ifndef __INPUT_RECEIVER_H__
#define __INPUT_RECEIVER_H__

#include "../../common/include/thread.h"
#include "../../common/include/protocol.h"
#include "../../common/include/protected_queue.h"
#include "../../common/include/action.h"
#include <iostream>

class InputReceiver: public Thread {
private:
    bool keep_running;
    Protocol *protocol;
    ProtectedQueue<uint8_t> inputs;

public:
    InputReceiver(Protocol *protocol);
    virtual void run() override;
    void stop();
};


#endif
