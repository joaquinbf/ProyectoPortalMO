#ifndef __DEAD_STATE_H__
#define __DEAD_STATE_H__

#include "../../../../common/include/types.h"
#include "chell_state.h"

class Chell;

class DeadState: public ChellState {
private:
    unsigned int step_count;
    const unsigned int MAX_STEPS = 60;

public:
    DeadState(Chell *chell);
    virtual void handleBeginContactWith(Bullet *bullet) override;
    virtual void applyStateAction() override;
};

#endif
