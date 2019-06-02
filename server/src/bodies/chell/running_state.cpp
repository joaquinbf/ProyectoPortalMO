#include "../../../include/bodies/chell/running_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

#include <iostream>

RunningState::RunningState(Chell *chell):
    ChellState(chell, STATUS::CHELL_RUNNING) {
}

void RunningState::pressLeft() {
    this->chell->applyLinearImpulseToLeft();
}

void RunningState::releaseLeft() {
    this->chell->changeStateToIdle();
}

void RunningState::pressRight() {
    this->chell->applyLinearImpulseToRight();
}

void RunningState::releaseRight() {
    this->chell->changeStateToIdle();
}

void RunningState::updateStateOnTimer() {

}
