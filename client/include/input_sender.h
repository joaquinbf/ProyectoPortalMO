#ifndef __INPUT_SENDER_H__
#define __INPUT_SENDER_H__

#include "../../common/include/thread.h"

class InputSender: public Thread {
public:
    virtual void run() override;
};

#endif
