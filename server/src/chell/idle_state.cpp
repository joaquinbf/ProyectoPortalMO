#include "../../include/chell/idle_state.h"
#include "../../include/chell/chell.h"

IdleState::IdleState(Chell *chell):
    ChellState(chell) {
}

void IdleState::left() {
    this->getChell()->faceLeft();
    this->getChell()->changeStateToRunning();
}

void IdleState::right() {
    this->getChell()->faceRight();
    this->getChell()->changeStateToRunning();
}

void IdleState::up() {
    this->getChell()->changeStateToJumping();
}

void IdleState::stopLeft() {
}

void IdleState::stopRight() {
}
