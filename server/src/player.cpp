#include "../include/player.h"

Player::Player(Socket socket):
    protocol(std::move(socket)),
    player_id(0),
    inputsPtr(nullptr),
    inputReceiver(protocol),
    updateSender(protocol) {
}

void Player::start() {
    this->inputReceiver.start();
    this->updateSender.start();
}

void Player::stop() {
    this->inputReceiver.stop();
    this->updateSender.stop();
}

void Player::sendChellIdToClient() const{
    this->protocol.sendQuad(this->player_id);
}

void Player::setInputPtr(ProtectedQueue<Action>* ptr){
	this->inputReceiver.setInputPtr(ptr);
}
