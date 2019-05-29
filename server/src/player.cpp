#include "../include/player.h"
#include "../include/match.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"

Player::Player(Socket &&socket, Match *match):
    keep_running(true),
    socket(std::move(socket)),
    match(match) {
}

void Player::run() {
    while (this->keep_running) {
    }
}

void Player::stop() {
    this->keep_running = false;
}
