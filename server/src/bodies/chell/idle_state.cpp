#include "../../../include/bodies/chell/idle_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

IdleState::IdleState(Chell *chell):
    ChellState(chell, STATUS::CHELL_IDLE) {
}

void IdleState::pressLeft() {
    this->chell->faceLeft();
    this->chell->changeStateToRunning();
}

void IdleState::releaseLeft() {
}

void IdleState::pressRight() {
    this->chell->faceRight();
    this->chell->changeStateToRunning();
}

void IdleState::releaseRight() {
}

void IdleState::updateStateOnTimer() {
}
