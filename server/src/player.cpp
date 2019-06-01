#include "../include/player.h"

Player::Player(Socket socket):
    protocol(std::move(socket)),
    inputReceiver(protocol),
    updateSender(protocol,&this->updates) {
}

Player::~Player(){
    try{
        this->protocol.close();
    } catch (const ConnectionErrorException &e){

    }
    this->inputReceiver.stop();
    this->updateSender.stop();
    this->inputReceiver.join();
    this->updateSender.join();
}

void Player::start() {
    this->inputReceiver.start();
    this->updateSender.start();
}

void Player::sendChellIdToClient(uint32_t id) const{
    this->protocol.sendQuad(id);
}

void Player::setInputPtr(ProtectedQueue<Action>* ptr){
	this->inputReceiver.setInputPtr(ptr);
}

ProtectedQueue<Update>* Player::getUpdatesPtr(){
    return &this->updates;
}

void Player::pushBackUpdate(Update update){
    this->updates.push(update);
}
