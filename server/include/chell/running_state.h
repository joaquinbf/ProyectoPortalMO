#ifndef __RUNNING_STATE_H__
#define __RUNNING_STATE_H__

#include "chell_state.h"

class RunningState: public ChellState {
public:
    RunningState(Chell *chell);
    virtual void keyLeft() override;
    virtual void keyRight() override;
    virtual void keyJump() override;
    virtual void stopKeyLeft() override;
};

#endif
