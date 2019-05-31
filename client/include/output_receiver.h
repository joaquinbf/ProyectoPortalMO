#ifndef __OUTPUT_RECEIVER_H__
#define __OUTPUT_RECEIVER_H__

#include "../../common/include/thread.h"

class OutputReceiver: public Thread {
public:
    virtual void run() override;
};

#endif
