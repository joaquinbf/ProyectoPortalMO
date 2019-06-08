#include "../../../include/bodies/chell/chell_state.h"

#include "../../../include/bodies/chell/chell.h"

ChellState::ChellState(Chell *chell, STATUS status):
    chell(chell),
    status(status) {
}

STATUS ChellState::getStatus() const {
    return this->status;
}

void ChellState::pressLeft() {

}

void ChellState::releaseLeft() {

}

void ChellState::pressRight() {

}

void ChellState::releaseRight() {

}

void ChellState::pressUp() {

}

void ChellState::releaseUp() {

}

void ChellState::land(){
}


void ChellState::applyStateAction() {
}

void ChellState::startTimer() {
    this->timer.start();
}
