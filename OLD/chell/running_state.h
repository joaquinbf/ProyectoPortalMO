#ifndef __RUNNING_STATE_H__
#define __RUNNING_STATE_H__

#include "chell_state.h"

class RunningState: public ChellState {
public:
    RunningState(Chell *chell);
    virtual void left() override;
    virtual void right() override;
    virtual void up() override;
    virtual void stopLeft() override;
    virtual void stopRight() override;
};

#endif
