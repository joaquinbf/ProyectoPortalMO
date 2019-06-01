#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

#include "../../../../common/include/timer.h"

class Chell;

class ChellState {
protected:
    Chell *chell;
    Timer timer;

public:
    ChellState(Chell *chell);
    virtual void pressLeft() = 0;
    virtual void releaseLeft() = 0;
};

#endif
