#include "../../../include/bodies/gate/closed_gate_state.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/gate/gate_state.h"

ClosedGateState::ClosedGateState(Gate *gate):
    GateState(gate, STATUS::GATE_CLOSED) {
}

void ClosedGateState::tryChangeState() {
    if (this->gate->conditionIsMeet()) {
        this->gate->changeStateToOpening();
    }
}

void ClosedGateState::applyStateAction() {
}
