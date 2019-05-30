#include "../include/player.h"
#include "../include/match.h"
#include "../include/input_receiver.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include <iostream>

Player::Player(Socket socket, Match *match):
    keep_running(true),
    protocol(std::move(socket)),
    match(match),
    input_receiver(&this->protocol, this->match->getCommandQueue()) {
}

Player::~Player() {
    this->protocol.close();
}

void Player::run() {
    this->chell = this->match->createChell();
    std::cout << "chell: " << this->chell
              << " id: " << this->chell->getBodyId()
              << std::endl;
    this->input_receiver.start();
}

void Player::stop() {
    this->keep_running = false;
    this->input_receiver.stop();
    this->input_receiver.join();
}

bool Player::isFinished() {
    return this->input_receiver.isFinished();
}
