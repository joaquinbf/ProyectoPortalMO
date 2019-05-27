#ifndef __JUMPING_STATE_H__
#define __JUMPING_STATE_H__

#include "chell_state.h"

class JumpingState: public ChellState {
public:
    JumpingState(Chell *chell);
    virtual void keyLeft() override;
    virtual void keyRight() override;
    virtual void keyJump() override;
};

#endif
