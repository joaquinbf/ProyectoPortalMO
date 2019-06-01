#include "../../../include/bodies/chell/idle_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

IdleState::IdleState(Chell *chell):
    ChellState(chell) {
}

void IdleState::pressLeft() {
    this->chell->faceLeft();
    this->chell->changeStateToRunning();
}

void IdleState::releaseLeft() {
    this->chell->faceRight();
    this->chell->changeStateToRunning();
}

void IdleState::updateStateOnTimer() {
}
