#include "../../../include/bodies/gate/opening_gate_state.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/gate/gate_state.h"

OpeningGateState::OpeningGateState(Gate *gate):
    GateState(gate, STATUS::GATE_OPENING) {
}

void OpeningGateState::tryChangeState() {
    if (this->gate->conditionIsMeet()) {
        this->gate->changeStateToOpening();
    }
}
