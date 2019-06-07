#ifndef __CLOSED_GATE_STATE_H__
#define __CLOSED_GATE_STATE_H__

#include "gate_state.h"

class Gate;

class ClosedGateState: public GateState {
public:
    ClosedGateState(Gate *gate);
    virtual void tryChangeState();
};

#endif
