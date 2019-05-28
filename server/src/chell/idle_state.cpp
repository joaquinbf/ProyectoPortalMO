#include "../../include/chell/idle_state.h"
#include "../../include/chell/chell.h"

IdleState::IdleState(Chell *chell):
    ChellState(chell) {
}

void IdleState::keyLeft() {
    this->getChell()->faceLeft();
    this->getChell()->changeToRunningState();
}

void IdleState::keyRight() {
    this->getChell()->faceRight();
    this->getChell()->changeToRunningState();
}

void IdleState::keyJump() {
    this->getChell()->changeToJumpingState();
}

void IdleState::stopKeyLeft() {
}
