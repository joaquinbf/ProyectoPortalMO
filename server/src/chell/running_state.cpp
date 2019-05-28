#include "../../include/chell/running_state.h"
#include "../../include/chell/chell.h"

RunningState::RunningState(Chell *chell):
    ChellState(chell) {
}

void RunningState::keyLeft() {
    this->getChell()->faceLeft();
    this->getChell()->applyLinearImpulseLeft();
}

void RunningState::keyRight() {
    this->getChell()->faceLeft();
    this->getChell()->applyLinearImpulseRight();
}

void RunningState::keyJump() {
    this->getChell()->changeToJumpingState();
}

void RunningState::stopKeyLeft() {
    this->getChell()->applyLinearImpulseStopLeft();
    }
