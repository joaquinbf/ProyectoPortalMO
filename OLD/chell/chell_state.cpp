#include "../../include/chell/chell_state.h"

ChellState::ChellState(Chell *chell):
    chell(chell) {
}


ChellState::~ChellState() {
}

Chell *ChellState::getChell() {
    return this->chell;
}
