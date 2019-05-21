#include "../include/player.h"


Player::Player(Socket &socket):
    socket(std::move(socket)),
    keep_running(true) {
}

void Player::run() {
    this->keep_running = true;
}
