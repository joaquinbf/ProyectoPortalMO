#include "../../../include/bodies/chell/jumping_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

#include <iostream>

JumpingState::JumpingState(Chell *chell):
    ChellState(chell, STATUS::CHELL_JUMPING) {
}

void JumpingState::pressLeft() {
    this->chell->applyLinearImpulseToLeft();
}

void JumpingState::releaseLeft() {
    this->chell->stopLeftMovement();
    this->chell->changeStateToIdle();
}

void JumpingState::pressRight() {
    this->chell->applyLinearImpulseToRight();
}

void JumpingState::releaseRight() {
    this->chell->stopRightMovement();
    this->chell->changeStateToIdle();
}
