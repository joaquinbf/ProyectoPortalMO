#include "../../include/chell/running_state.h"
#include "../../include/chell/chell.h"

RunningState::RunningState(Chell *chell):
    ChellState(chell) {
}

void RunningState::keyLeft() {
    this->getChell()->faceLeft();
}
