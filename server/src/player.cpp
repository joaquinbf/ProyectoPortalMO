#include "../include/player.h"
#include "../include/world.h"
#include "../../common/include/thread.h"
#include "../../common/include/socket.h"
#include <iostream>
#include <vector>

Player::Player(Socket socket, World *world):
    keep_running(true),
    protocol(std::move(socket)),
    input_recv(&this->protocol),
    world(world),
    update_sender(&this->protocol) {
}

void Player::run() {
    std::cout << "corriendo en player " << std::endl;
    std::cout << "sendBodiesToPlayer" << std::endl;
    this->world->sendBodiesToPlayer(this);

    std::cout << "START inpur recv" << std::endl;
    this->input_recv.start();

    std::cout << "START update sender" << std::endl;
    this->update_sender.start();

    while (this->keep_running) {
    }

    this->input_recv.stop();
    this->input_recv.join();

    this->update_sender.stop();
    this->update_sender.join();
}

void Player::stop() {
    this->keep_running = false;
}

InputReceiver *Player::getInputReceiver() {
    return &this->input_recv;
}

Protocol *Player::getProtocol() {
    return &this->protocol;
}

void Player::sendBodies(const std::vector<Body *> &bodies) {
    std::cout << "send bodies" << std::endl;
    this->protocol.sendQuad(bodies.size());
    this->protocol.sendCreator(CreatorMessage(ENTITY::CHELL, 0, -1, -18));
}

UpdateSender *Player::getUpdateSender() {
    return &this->update_sender;
}
