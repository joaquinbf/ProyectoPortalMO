#ifndef __GATE_STATE_H__
#define __GATE_STATE_H__

#include "../../../../common/include/types.h"

class Gate;

class GateState {
private:
    Gate *gate;
    const STATUS status;

public:
    GateState(Gate *gate, STATUS status);
    virtual ~GateState();
    virtual void notifyStateChange() = 0;
    STATUS getStatus() const;
};

#endif
