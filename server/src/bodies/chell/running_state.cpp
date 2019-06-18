#include "../../../include/bodies/chell/running_state.h"

#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

#include <iostream>

RunningState::RunningState(Chell *chell):
    ChellState(chell, STATUS::CHELL_RUNNING) {
}

void RunningState::pressLeft() {
    this->chell->faceLeft();
}

void RunningState::releaseLeft() {
    this->chell->stopLeftMovement();
    this->chell->changeStateToIdle();
}

void RunningState::pressRight() {
    this->chell->faceRight();
}

void RunningState::releaseRight() {
    this->chell->stopRightMovement();
    this->chell->changeStateToIdle();
}

void RunningState::pressUp() {
    this->chell->applyLinearImpulseToUp();
    this->chell->changeStateToJumping();
}

void RunningState::applyStateAction() {
    if (this->chell->isFacingRight()) {
        this->chell->applyLinearImpulseToRight();
    } else {
        this->chell->applyLinearImpulseToLeft();
    }
}
