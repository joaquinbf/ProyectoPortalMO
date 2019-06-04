#include "../../../include/bodies/gate/gate_state.h"
#include "../../../include/bodies/gate/gate.h"

GateState::GateState(Gate *gate, STATUS status):
    gate(gate),
    status(status) {
}

GateState::~GateState() {
}

STATUS GateState::getStatus() const {
    return this->status;
}
