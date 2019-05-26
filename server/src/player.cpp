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
    std::cout << "input recv: parado" << std::endl;

    this->input_recv.join();
    std::cout << "input recv: joineado" << std::endl;

    this->update_sender.stop();
    std::cout << "update sender: parado" << std::endl;

    this->update_sender.join();
    std::cout << "update sender: joineado" << std::endl;
}

void Player::stop() {
    this->protocol.close();
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
    this->protocol.sendCreator(CreatorMessage(ENTITY::CHELL, 0, 0, -200, 1));
    this->protocol.sendCreator(CreatorMessage(ENTITY::STONE_BLOCK, 1, -384, 100, 1));
    this->protocol.sendCreator(CreatorMessage(ENTITY::STONE_BLOCK, 2, -196, 100, 1));
    this->protocol.sendCreator(CreatorMessage(ENTITY::STONE_BLOCK, 3, 0, 100, 1));
    this->protocol.sendCreator(CreatorMessage(ENTITY::STONE_BLOCK, 4, 196, 100, 1));
    this->protocol.sendCreator(CreatorMessage(ENTITY::STONE_BLOCK, 5, 384, 100, 1));

}

UpdateSender *Player::getUpdateSender() {
    return &this->update_sender;
}
