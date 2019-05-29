#include "../include/player.h"
#include "../include/match.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include <iostream>

Player::Player(Socket socket, Match *match):
    keep_running(true),
    protocol(std::move(socket)),
    match(match) {
}

Player::~Player() {
    this->protocol.close();
}

void Player::run() {
    this->chell = this->match->createChell();
    std::cout << "chell: " << this->chell << std::endl;
}

void Player::stop() {
    this->keep_running = false;
}
