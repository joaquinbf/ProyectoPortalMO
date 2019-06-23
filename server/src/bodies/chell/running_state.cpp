#include "../../../include/bodies/chell/running_state.h"
#include "../../../include/bodies/chell/chell.h"
#include "../../../include/bodies/chell/chell_state.h"

#include <iostream>

RunningState::RunningState(Chell *chell):
    ChellState(chell, STATUS::CHELL_RUNNING) {
}

void RunningState::pressLeft() {
    if (this->chell->isFacingRight()) {
        this->chell->stopRightMovement();
        this->chell->changeStateToTurning();
    }
    this->chell->faceLeft();
}

void RunningState::releaseLeft() {
    this->chell->stopLeftMovement();
    this->chell->changeStateToStopping();
}

void RunningState::pressRight() {
    if (this->chell->isFacingLeft()) {
        this->chell->stopLeftMovement();
        this->chell->changeStateToTurning();
    }
    this->chell->faceRight();
}

void RunningState::releaseRight() {
    this->chell->stopRightMovement();
    this->chell->changeStateToStopping();
}

void RunningState::pressUp() {
    this->chell->applyLinearImpulseToUp();
    this->chell->changeStateToJumping();
}

void RunningState::applyStateAction() {
    if (!this->chell->hasReachedMaxHorizontalSpeed()) {
        if (this->chell->isFacingRight()) {
            this->chell->applyLinearImpulseToRight();
        } else {
            this->chell->applyLinearImpulseToLeft();
        }
    }
}
