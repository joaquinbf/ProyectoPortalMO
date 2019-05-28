#include "../include/match.h"
#include <iostream>

Match::Match():
    GRAVITY(0.0, -9.8),
    b2world(this->GRAVITY),
    keep_running(true) {
    this->world.setB2World(&(this->b2world));
}

void Match::run() {
    while (this->keep_running) {
        this->world.step();
    }
}

void Match::stop() {
    this->keep_running = false;
}

void Match::addPlayer(Socket socket) {
    std::cout << "void Match::addPlayer(Socket socket)" << std::endl;
    this->world.addPlayer(std::move(socket));
}
