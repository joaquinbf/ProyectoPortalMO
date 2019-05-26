#include "../include/chell_state.h"
#include "../include/falling_state.h"

ChellState::ChellState(Chell *chell, STATUS status):
    chell(chell),
    status(status) {
}

STATUS ChellState::getStatus() {
    return this->status;
}

Chell *ChellState::getChell() {
    return this->chell;
}

ChellState::~ChellState() {
}

void ChellState::changeStateIfFalling() {
    if (this->chell->isFalling()) {
        this->chell->updateCurrentState(new FallingState(this->chell));
    }
}

void ChellState::stop() {
    this->chell->stopVelocityOnX();
}
