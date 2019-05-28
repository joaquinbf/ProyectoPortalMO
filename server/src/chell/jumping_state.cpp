#include "../../include/chell/jumping_state.h"
#include "../../include/chell/chell.h"

JumpingState::JumpingState(Chell *chell):
    ChellState(chell) {
}

void JumpingState::left() {
    this->getChell()->faceLeft();
    this->getChell()->applyLinearImpulseLeft();
}

void JumpingState::right() {
    this->getChell()->faceRight();
    this->getChell()->applyLinearImpulseRight();
}

void JumpingState::up() {
    this->getChell()->applyLinearImpulseUp();
}

void JumpingState::stopLeft() {
}

void JumpingState::stopRight() {
}
