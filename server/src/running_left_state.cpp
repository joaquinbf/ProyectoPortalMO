#include "../include/running_left_state.h"

RunningLeftState::RunningLeftState(Chell *chell):
    ChellState(chell, STATUS::CHELL_RUNNING) {
}

void RunningLeftState::runLeft() {
    this->getChell()->setOldState(0);
}
