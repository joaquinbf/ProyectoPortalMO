#include "../../include/chell/jumping_state.h"
#include "../../include/chell/chell.h"

JumpingState::JumpingState(Chell *chell):
    ChellState(chell) {
}

void JumpingState::keyLeft() {
    this->getChell()->faceLeft();
    this->getChell()->applyLinearImpulseLeft();
}

void JumpingState::keyRight() {
    this->getChell()->faceRight();
    this->getChell()->applyLinearImpulseRight();
}

void JumpingState::keyJump() {
    this->getChell()->applyLinearImpulseUp();
}
