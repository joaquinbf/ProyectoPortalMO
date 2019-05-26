#include "../include/idle_state.h"
#include "../include/running_left_state.h"

IdleState::IdleState(Chell *chell):
    ChellState(chell, STATUS::CHELL_IDLE) {
}

void IdleState::runLeft() {
    Chell *chell = this->getChell();
    chell->applyLinearImpulseToLeft();
    chell->updateCurrentState(new RunningLeftState(chell));
}
