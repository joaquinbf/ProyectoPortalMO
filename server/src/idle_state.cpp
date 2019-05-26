#include "../include/idle_state.h"
#include "../include/running_left_state.h"

IdleState::IdleState(Chell *chell):
    ChellState(chell) {
}

ChellState *IdleState::runLeft() {
    return new RunningLeftState(this->getChell());
}
