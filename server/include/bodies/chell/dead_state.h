#ifndef __DEAD_STATE_H__
#define __DEAD_STATE_H__

#include "../../../../common/include/types.h"
#include "chell_state.h"

class Chell;

class DeadState: public ChellState {
public:
    DeadState(Chell *chell);
};

#endif
