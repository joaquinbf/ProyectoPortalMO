#ifndef __ACCEPTER_H__
#define __ACCEPTER_H__

#include "../../common/include/thread.h"

class Accepter: public Thread {
public:
    virtual void run() override;
};

#endif
