#include "../../include/chell/idle_state.h"
#include "../../include/chell/chell.h"

IdleState::IdleState(Chell *chell):
    ChellState(chell) {
}

void IdleState::keyLeft() {
    this->getChell()->keyLeft();
}
