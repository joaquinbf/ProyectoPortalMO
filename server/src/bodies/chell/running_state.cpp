#include "../../../include/bodies/chell/running_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

RunningState::RunningState(Chell *chell):
    ChellState(chell) {
}

void RunningState::pressLeft() {
    this->chell->applyLinearImpulseToLeft();
}

void RunningState::releaseLeft() {
    this->chell->stopLeftMovement();
}

void RunningState::updateStateOnTimer() {

}
