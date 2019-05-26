#ifndef __FALLING_STATE_H__
#define __FALLING_STATE_H__

#include "chell_state.h"
#include "chell.h"

class FallingState: public ChellState {
public:
    FallingState(Chell *chell);
    void runLeft() override;
    virtual void changeStateIfFalling() override;
    virtual void stop() override;
};

#endif
