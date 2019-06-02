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
    this->chell->stopLeftMovement();
}

void IdleState::pressRight() {
    this->chell->faceRight();
    this->chell->changeStateToRunning();
}

void IdleState::releaseRight() {
    this->chell->stopRightMovement();
}

void IdleState::updateStateOnTimer() {
}
