#include "../include/input_receiver.h"
#include <iostream>

InputReceiver::InputReceiver(
    Player *player,
    ProtectedQueue<Command *> *commands):
    player(player),
    commands(commands),
    keep_running(true) {
}

void InputReceiver::run() {
    std::cout << "input recv run " << std::endl;

    while (this->keep_running) {
    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}
