#ifndef __RUNNING_STATE_H__
#define __RUNNING_STATE_H__

#include "chell_state.h"

class Chell;

class RunningState: public ChellState {
public:
    RunningState(Chell *chell);
    virtual void pressLeft() override;
    virtual void releaseLeft() override;
    virtual void pressRight() override;
    virtual void releaseRight() override;
    virtual void applyStateAction() override;
};

#endif
