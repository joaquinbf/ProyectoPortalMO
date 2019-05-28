#include "../include/player.h"

Player::Player(
    Socket socket,
    Chell *chell,
    ProtectedQueue<Command> *commands):
    protocol(std::move(socket)),
    chell(chell),
    input_receiver(&this->protocol, commands) {
}

void Player::start() {

}

void Player::stop() {

}
