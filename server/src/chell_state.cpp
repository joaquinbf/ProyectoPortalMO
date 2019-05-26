#include "../include/chell_state.h"

ChellState::ChellState(Chell *chell):
    chell(chell) {
}

Chell *ChellState::getChell() {
    return this->chell;
}


ChellState::~ChellState() {
}
