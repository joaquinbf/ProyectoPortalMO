#ifndef __CLOSED_GATE_H__
#define __CLOSED_GATE_H__

#include "gate_state.h"

class Gate;

class ClosedGate: public GateState {
public:
    ClosedGate(Gate *gate);
    virtual void notifyStateChange();
};

#endif
