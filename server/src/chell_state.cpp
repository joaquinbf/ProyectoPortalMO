#include "../include/chell_state.h"

ChellState::ChellState(Chell *chell, STATUS status):
    chell(chell),
    status(status) {
}

STATUS ChellState::getStatus() {
    return this->status;
}

Chell *ChellState::getChell() {
    return this->chell;
}


ChellState::~ChellState() {
}
