#ifndef __UPDATE_SENDER_H__
#define __UPDATE_SENDER_H__

#include "../../common/include/thread.h"

class UpdateSender: public Thread {
public:
    virtual void run() override;
};

#endif
