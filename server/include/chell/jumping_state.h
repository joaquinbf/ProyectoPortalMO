#ifndef __JUMPING_STATE_H__
#define __JUMPING_STATE_H__

#include "chell_state.h"

class JumpingState: public ChellState {
public:
    JumpingState(Chell *chell);
    virtual void left() override;
    virtual void right() override;
    virtual void up() override;
    virtual void stopLeft() override;
    virtual void stopRight() override;
};

#endif
