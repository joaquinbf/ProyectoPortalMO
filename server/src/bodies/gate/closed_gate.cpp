#include "../../../include/bodies/gate/closed_gate.h"

ClosedGate::ClosedGate(Gate *gate):
    GateState(gate, STATUS::GATE_CLOSED) {
}

void ClosedGate::notifyStateChange() {

}
