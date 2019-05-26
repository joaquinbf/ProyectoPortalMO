#ifndef __IDLE_STATE_H__
#define __IDLE_STATE_H__

#include "chell_state.h"
#include "running_left_state.h"
#include "chell.h"

class IdleState: public ChellState {
public:
    IdleState(Chell *chell);
    virtual void runLeft() override;
};

#endif
