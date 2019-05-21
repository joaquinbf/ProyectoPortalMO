#include "../include/player.h"

Player::Player(Socket &socket):
    socket(std::move(socket)){
}

void Player::run() {
    
}
