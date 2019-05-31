#include "../include/player.h"

Player::Player(Socket socket):
    protocol(std::move(socket)),
    player_id(0),
    inputsPtr(nullptr) {
}

void Player::start() {
    //this->input_receiver.start();
}

void Player::stop() {
    //this->input_receiver.stop();
}

void Player::sendChellIdToClient() const{
    this->protocol.sendQuad(this->player_id);
}

void Player::setInputPtr(ProtectedQueue<Action>* ptr){
	this->inputsPtr = ptr;
}
