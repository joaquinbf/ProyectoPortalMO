#include "../include/idle_state.h"
#include "../include/running_left_state.h"
#include <iostream>

IdleState::IdleState(Chell *chell):
    ChellState(chell, STATUS::CHELL_IDLE) {
}

void IdleState::runLeft() {
    std::cout << "IdleState::runLeft()" << std::endl;
    Chell *chell = this->getChell();
    chell->applyLinearImpulseToLeft();
    chell->updateCurrentState(new RunningLeftState(chell));
}
