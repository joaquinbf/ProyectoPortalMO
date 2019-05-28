#include "../include/player.h"

Player::Player(
    Socket socket,
    Chell *chell,
    ProtectedQueue<Command *> *commands):
    protocol(std::move(socket)),
    chell(chell),
    input_receiver(&this->protocol, commands) {
}

void Player::start() {
    this->input_receiver.start();
}

void Player::stop() {
    this->protocol.close();
    this->input_receiver.stop();
    this->input_receiver.join();
}
