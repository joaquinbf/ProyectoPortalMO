#ifndef __IDLE_STATE_H__
#define __IDLE_STATE_H__

#include "chell_state.h"

class IdleState: public ChellState {
public:
    IdleState(Chell *chell);
    virtual void left() override;
    virtual void right() override;
    virtual void up() override;
    virtual void stopLeft() override;
    virtual void stopRight() override;
};

#endif
