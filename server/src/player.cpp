#include "../include/player.h"

Player::Player(Socket socket, ProtectedQueue<Command*> *commands):
    protocol(std::move(socket)),
    player_id(0),
    input_receiver(&this->protocol, commands) {
}

void Player::start() {
    this->input_receiver.start();
}

void Player::stop() {
    this->input_receiver.stop();
}
