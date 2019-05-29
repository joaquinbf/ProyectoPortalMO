#ifndef __MATCH_H__
#define __MATCH_H__

#include "../../common/include/thread.h"

class Match: public Thread {
private:
    bool keep_running;
public:
    virtual void run() override;
    void stop();
};

#endif
