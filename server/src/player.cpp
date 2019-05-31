#include "../include/player.h"

Player::Player(Socket socket):
    protocol(std::move(socket)),
    player_id(0),
    inputReceiver(protocol),
    updateSender(protocol) {
}

Player::~Player(){
    this->protocol.close();
    this->inputReceiver.stop();
    this->updateSender.stop();
    this->inputReceiver.join();
    this->updateSender.join();
}

void Player::start() {
    this->inputReceiver.start();
    this->updateSender.start();
}

void Player::sendChellIdToClient() const{
    this->protocol.sendQuad(this->player_id);
}

void Player::setInputPtr(ProtectedQueue<Action>* ptr){
	this->inputReceiver.setInputPtr(ptr);
}
