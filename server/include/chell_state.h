#ifndef __CHELL_STATE_H__
#define __CHELL_STATE_H__

#include "../../common/include/status.h"

class Chell;

class ChellState {
private:
    Chell *chell;
    STATUS status;

public:
    ChellState(Chell *chell, STATUS status);
    Chell *getChell();
    STATUS getStatus();
    virtual ~ChellState();
    virtual void changeStateIfFalling();
    virtual void runLeft() = 0;
};

#endif
