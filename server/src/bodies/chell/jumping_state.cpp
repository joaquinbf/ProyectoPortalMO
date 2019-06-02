#include "../../../include/bodies/chell/jumping_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

#include <iostream>

JumpingState::JumpingState(Chell *chell):
    ChellState(chell, STATUS::CHELL_RUNNING) {
}

void JumpingState::pressLeft() {
    this->chell->applyLinearImpulseToLeft();
}

void JumpingState::releaseLeft() {
    std::cout << "void JumpingState::releaseLeft()" << std::endl;
    this->chell->stopLeftMovement();
    this->chell->changeStateToIdle();
}

void JumpingState::pressRight() {
    this->chell->applyLinearImpulseToRight();
}

void JumpingState::releaseRight() {
    std::cout << "void JumpingState::releaseRight()" << std::endl;
    this->chell->stopRightMovement();
    this->chell->changeStateToIdle();
}
