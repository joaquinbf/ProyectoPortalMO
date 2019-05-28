#include "../include/match.h"
#include <iostream>

Match::Match():
    GRAVITY(0.0, -9.8),
    b2world(this->GRAVITY),
    keep_running(true) {
    this->world.setB2World(&(this->b2world));
}

void Match::run() {
    // hardcoded
    this->world.setB2World(&this->b2world);
    this->world.setGravity(0.0, -20);
    this->world.addGround(-100, -50, 100, -50);

    float start = -86.4;
    float step = 19.2;
    for (int i = 0; i < 7; i++) {
        this->world.addSquareStoneBlock(start + step*i, -30);
    }

    while (this->keep_running) {
        this->world.step();
    }
}

void Match::stop() {
    this->keep_running = false;
}

void Match::addPlayer(Socket socket) {
    this->world.addPlayer(std::move(socket));
}
