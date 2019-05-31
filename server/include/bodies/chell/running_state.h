#ifndef __RUNNING_STATE_H__
#define __RUNNING_STATE_H__

#include "chell_state.h"

class Chell;

class RunningState: public ChellState {
public:
    RunningState(Chell *chell);
};

#endif
