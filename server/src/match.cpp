#include "../include/match.h"

Match::Match():
    GRAVITY(0.0, -9.8),
    b2world(this->GRAVITY),
    keep_running(true) {
    this->world.setB2World(&this->b2world);
}

void Match::run() {
    while (this->keep_running) {
        this->world.step();
    }
}

void Match::stop() {
    this->keep_running = false;
}
