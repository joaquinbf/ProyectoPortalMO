#ifndef __RUNNING_LEFT_STATE_H__
#define __RUNNING_LEFT_STATE_H__

#include "chell_state.h"

class RunningLeftState: public ChellState {
public:
    RunningLeftState(Chell *chell);
    virtual ChellState *runLeft() override;
};

#endif
