#include "../../../include/bodies/chell/running_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

#include <iostream>

RunningState::RunningState(Chell *chell):
    ChellState(chell, STATUS::CHELL_RUNNING) {
}

void RunningState::pressLeft() {
    this->chell->applyLinearImpulseToLeft();
}

void RunningState::releaseLeft() {
    std::cout << "void RunningState::releaseLeft()" << std::endl;
    this->chell->stopLeftMovement();
    this->chell->changeStateToIdle();
}

void RunningState::pressRight() {
    this->chell->applyLinearImpulseToRight();
}

void RunningState::releaseRight() {
    std::cout << "void RunningState::releaseRight()" << std::endl;
    this->chell->stopRightMovement();
}

void RunningState::updateStateOnTimer() {

}
