#include "../include/input_receiver.h"

InputReceiver::InputReceiver(
    Player *player,
    ProtectedQueue<Command *> *commands):
    player(player),
    commands(commands),
    keep_running(true) {
}

void InputReceiver::run() {

    while (this->keep_running) {

    }
}

void InputReceiver::stop() {
    this->keep_running = false;
}
