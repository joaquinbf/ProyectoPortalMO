#include "../../../include/bodies/chell/turning_state.h"
#include "../../../include/bodies/chell/chell.h"

TurningState::TurningState(Chell *chell):
    ChellState(chell, STATUS::CHELL_TURNING) {
}

void TurningState::applyStateAction() {
    this->step_count++;
    if (this->step_count > this->MAX_STEPS) {
        this->chell->changeStateToRunning();
        this->resetStepCount();
    }
}

void TurningState::pressUp() {
    this->chell->applyLinearImpulseToUp();
    this->chell->changeStateToJumping();
}
