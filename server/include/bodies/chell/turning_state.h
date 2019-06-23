#ifndef __TURNING_STATE_H__
#define __TURNING_STATE_H__

#include "chell_state.h"

class Chell;

class TurningState: public ChellState {
private:
    const unsigned int MAX_STEPS = 8;
public:
    TurningState(Chell *chell);
    virtual void applyStateAction() override;
    virtual void pressUp() override;
};

#endif
