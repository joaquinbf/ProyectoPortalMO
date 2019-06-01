#include "../../../include/bodies/chell/running_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

RunningState::RunningState(Chell *chell):
    ChellState(chell) {
}

void RunningState::pressLeft() {
    this->applyLinearImpulseToLeft();
}

void RunningState::releaseLeft() {
    this->stopLeftMovement();
}

void RunningState::updateStateOnTimer() {

}
