#include "../../include/chell/running_state.h"
#include "../../include/chell/chell.h"

RunningState::RunningState(Chell *chell):
    ChellState(chell) {
}

void RunningState::left() {
    this->getChell()->faceLeft();
    this->getChell()->applyLinearImpulseLeft();
}

void RunningState::right() {
    this->getChell()->faceLeft();
    this->getChell()->applyLinearImpulseRight();
}

void RunningState::up() {
    this->getChell()->changeStateToJumping();
}

void RunningState::stopLeft() {
    this->getChell()->applyLinearImpulseStopLeft();
}

void RunningState::stopRight() {
    this->getChell()->applyLinearImpulseStopRight();
}
