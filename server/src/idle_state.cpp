#include "../include/idle_state.h"
#include "../include/running_left_state.h"

IdleState::IdleState(Chell *chell):
    ChellState(chell) {
}

void IdleState::runLeft() {
    Chell *chell = this->getChell();
    chell->updateCurrentState(new RunningLeftState(chell));
}
