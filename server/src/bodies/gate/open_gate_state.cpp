#include "../../../include/bodies/gate/open_gate_state.h"
#include "../../../include/bodies/gate/gate.h"
#include "../../../include/bodies/gate/gate_state.h"

OpenGateState::OpenGateState(Gate *gate):
    GateState(gate, STATUS::GATE_OPENED) {
}

void OpenGateState::tryChangeState() {
    if (this->gate->conditionIsMeet()) {
    }
}

void OpenGateState::applyStateAction() {
}
