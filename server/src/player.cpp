#include "../include/player.h"
#include "../include/world.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include <iostream>

Player::Player(Socket &socket):
    keep_running(true),
    protocol(std::move(socket)),
    input_recv(&this->protocol) {
}

void Player::run() {
    std::cout << "corriendo en player " << std::endl;
    this->input_recv.start();
    this->input_recv.stop();
    this->input_recv.join();
}

void Player::stop() {
    this->keep_running = false;
}

InputReceiver *Player::getInputReceiver() {
    return &this->input_recv;
}

Protocol *Player::getProtocol() {
    return &this->protocol;
}
