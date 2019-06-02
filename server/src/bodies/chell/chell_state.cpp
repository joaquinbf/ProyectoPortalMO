#include "../../../include/bodies/chell/chell_state.h"

#include "../../../include/bodies/chell/chell.h"

ChellState::ChellState(Chell *chell, STATUS status):
    chell(chell),
    status(status) {
}

STATUS ChellState::getStatus() const {
    return this->status;
}

void ChellState::applyStateAction() {
}
