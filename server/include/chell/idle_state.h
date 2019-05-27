#ifndef __IDLE_STATE_H__
#define __IDLE_STATE_H__

#include "chell_state.h"
#include "../../include/chell/chell.h"

class IdleState: public ChellState {
public:
    IdleState(Chell *chell);
    virtual void keyLeft() override;
};

#endif
