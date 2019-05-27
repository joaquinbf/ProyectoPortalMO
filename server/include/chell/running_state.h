#ifndef __RUNNING_STATE_H__
#define __RUNNING_STATE_H__

#include "chell_state.h"

class RunningState: public ChellState {
public:
    RunningState(Chell *chell);
    virtual void keyLeft() override;
};

#endif
