#ifndef __IDLE_STATE_H__
#define __IDLE_STATE_H__

#include "chell_state.h"

class IdleState: public ChellState {
public:
    IdleState(Chell *chell);
    virtual void keyLeft() override;
    virtual void keyRight() override;
    virtual void keyJump() override;
};

#endif
