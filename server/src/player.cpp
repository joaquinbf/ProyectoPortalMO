#include "../include/player.h"
#include "../include/world.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include <iostream>
#include <vector>

Player::Player(Socket &socket):
    keep_running(true),
    protocol(std::move(socket)),
    input_recv(&this->protocol) {
}

void Player::run() {
    std::cout << "corriendo en player " << std::endl;
    this->input_recv.start();
    while (this->keep_running) {
    }
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

void Player::sendBodies(const std::vector<Body *> &bodies) {
    std::cout << "send bodies" << std::endl;
    this->protocol.sendQuad(bodies.size());
    this->protocol.sendCreator(CreatorMessage(ENTITY::CHELL, 0, -1, -18));
}
