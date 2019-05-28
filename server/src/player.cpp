#include "../include/player.h"

Player::Player(Socket socket, Chell *chell):
    protocol(std::move(socket)),
    chell(chell) {
}

void Player::start() {
    
}

void Player::stop() {

}
