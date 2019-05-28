#include "../include/player.h"

Player::Player(Socket socket, ProtectedQueue<Command*> *commands):
    protocol(std::move(socket)),
    player_id(0),
    input_receiver(this, commands) {
}

void Player::start() {
    this->input_receiver.start();
}

void Player::stop() {
    this->input_receiver.stop();
}

void Player::setChell(Chell *chell) {
    this->chell = chell;
}

void Player::sendChellIdToClient() {
    this->protocol.sendQuad(this->player_id);
}

void Player::sendUpdate(Update update) {
    this->protocol.sendUpdate(update);
}
