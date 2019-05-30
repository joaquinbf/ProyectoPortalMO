#include "../include/player.h"
#include "../include/match.h"
#include "../include/input_receiver.h"
#include "../include/update_sender.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include "../../common/include/protocol.h"
#include <iostream>

Player::Player(Socket socket, Match *match):
    keep_running(true),
    protocol(std::move(socket)),
    match(match),
    input_receiver(&this->protocol, this->match->getCommandQueue()),
    update_sender(&this->protocol) {
}

Player::~Player() {
}

void Player::run() {
    // std::cout << "void Player::run() " << std::endl;
    // this->chell = this->match->createChell();
    // std::cout << "chell: " << this->chell
    //           << " id: " << this->chell->getBodyId()
    //           << std::endl;
    // this->match->sendUpdatesTo(this->update_sender.getUpdateQueue());
    // this->input_receiver.start();
    // this->update_sender.start();
    std::cout << "ayy lmao" << std::endl;
    this->chell = this->match->getAviableChell();
    this->match->sendUpdatesTo(this->update_sender.getUpdateQueue());
    this->input_receiver.start();
    this->update_sender.start();
}

void Player::stop() {
    this->keep_running = false;
    try {
        this->protocol.close();
    } catch (const ConnectionErrorException &e) {
    }

    try {
        this->input_receiver.stop();
    } catch (const ConnectionErrorException &e) {
    }
    std::cout << "despues de input_receiver.stop()" << std::endl;
    this->input_receiver.join();
    std::cout << "despues de input_receiver.join()" << std::endl;
    try {
        this->update_sender.stop();
    } catch (const ConnectionErrorException &e) {
    }
    std::cout << "despues de update_sender.stop()" << std::endl;
    this->update_sender.join();
    std::cout << "despues de update_sender.join()" << std::endl;
}

bool Player::isFinished() {
    return this->input_receiver.isFinished();
}
