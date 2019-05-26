#include "../include/falling_state.h"

FallingState::FallingState(Chell *chell):
    ChellState(chell, STATUS::CHELL_FALLING) {
}

void FallingState::runLeft() {
}

void FallingState::changeStateIfFalling() {
}

void FallingState::stop() {
}
